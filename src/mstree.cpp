class MSTree {
    public:
    struct Node {
        vector<int> val;
    };
    
    int n;
    vector<Node> t;
    MSTree(int n) : n(n) {
        t.resize(4 * n);
    }
    
    void build(int v, int l, int r) {
        if (l == r - 1) {
            t[v].val.push_back(l);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid);
        build(2 * v + 2, mid, r);
        merge(t[2 * v + 1].val.begin(), t[2 * v + 1].val.end(), t[2 * v + 2].val.begin(), t[2 * v + 2].val.end(), back_inserter(t[v].val));
    }
    
    int query(int v, int l, int r, int ql, int qr, int mn, int mx) {
        if (qr <= l || r <= ql)
            return 0;
        if (ql <= l && r <= qr) {
            auto it = lower_bound(t[v].val.begin(), t[v].val.end(), mn);
            if (it == t[v].val.end() || (*it) >= mx)
                return 0;
            return lower_bound(t[v].val.begin(), t[v].val.end(), mx) - it;
        }
        int mid = (l + r) / 2;
        auto left = query(2 * v + 1, l, mid, ql, qr, mn, mx);
        auto right = query(2 * v + 2, mid, r, ql, qr, mn, mx);
        return left + right;
    }
};
