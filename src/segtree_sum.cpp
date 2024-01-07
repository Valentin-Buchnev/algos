class SegTreeSum {
    public:
    struct Node {
        ll val = 0;
        ll add = 0;
    };
    
    int n;
    vector<Node> t;
    SegTreeSum(int n) : n(n) {
        t.resize(4 * n);
    }
    
    void build(int v, int l, int r) {
        t[v].add = 0;
        if (l == r - 1) {
            t[v].val = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v + 1, l, mid);
        build(2 * v + 2, mid, r);
        t[v].val = t[2 * v + 1].val + t[2 * v + 2].val;    
    }
    
    ll query(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql)
            return 0;
        if (ql <= l && r <= qr) {
            return t[v].val + t[v].add;
        }
        int mid = (l + r) / 2;
        auto left = query(2 * v + 1, l, mid, ql, qr);
        auto right = query(2 * v + 2, mid, r, ql, qr);
        return left + right + t[v].add;
    }
    
    void update(int v, int l, int r, int ql, int qr, ll d) {
        if (qr <= l || r <= ql)
            return;
        if (ql <= l && r <= qr) {
            t[v].add = t[v].add + d;
            return;
        }
        int mid = (l + r) / 2;
        update(2 * v + 1, l, mid, ql, qr, d);
        update(2 * v + 2, mid, r, ql, qr, d);
        t[v].val = t[2 * v + 1].val + t[2 * v + 1].add + t[2 * v + 2].val + t[2 * v + 2].add;
    }
};
