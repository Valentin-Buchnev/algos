class mint {
private:
    static const int MOD = 1e9 + 7;
    int val;
public:
    mint (ll x=0) {
        val = x % MOD;
        if (val < 0) 
            val += MOD;
    }
    mint (const mint& p) {
        val = p.val;
    }
    mint operator +(mint p) {
        return mint(val + p.val);
    }
    mint operator -(mint p) {
        return mint(val - p.val);
    }
    mint operator *(mint p) {
        return mint(val * 1LL * p.val);  
    }
    mint operator /(mint p) {
        return mint(val) * 1LL * binpow(p, MOD - 2);
    }
    void operator +=(mint p) {
        *this = *this + p;
    }
    void operator -=(mint p) {
        *this = *this - p;
    }
    void operator *=(mint p) {
        *this = *this * p;
    }
    void operator /=(mint p) {
        *this = *this / p;
    }
    mint binpow(mint p, int d) {
        if (d == 0)
            return mint(1);
        if (d % 2 == 0) {
            mint x = binpow(p, d / 2);
            return x * x;
        }
        return p * binpow(p, d - 1);
    }
    friend ostream &operator<<(ostream &out, mint p) {
        out << p.val;
        return out;
    }
};
