class SegTree {
    public:
    struct Node {
        ll val = 0;
        ll add = 0;
    };
    
    int n;
    vector<Node> t;
    SegTree(int n) : n(n) {
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
        t[v].val = max(t[2 * v + 1].val, t[2 * v + 2].val);    
    }
    
    ll query(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql)
            return -1e18;
        if (ql <= l && r <= qr) {
            return t[v].val + t[v].add;
        }
        int mid = (l + r) / 2;
        auto left = query(2 * v + 1, l, mid, ql, qr);
        auto right = query(2 * v + 2, mid, r, ql, qr);
        return max(left, right) + t[v].add;
    }
    
    void add(int v, int l, int r, int ql, int qr, ll d) {
        if (qr <= l || r <= ql)
            return;
        if (ql <= l && r <= qr) {
            t[v].add += d;
            return;
        }
        int mid = (l + r) / 2;
        add(2 * v + 1, l, mid, ql, qr, d);
        add(2 * v + 2, mid, r, ql, qr, d);
        t[v].val = max(t[2 * v + 1].val + t[2 * v + 1].add, t[2 * v + 2].val + t[2 * v + 2].add);
    }
};
