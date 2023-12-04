class mint {
private:
    static const int MOD = 998244353;
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
    const mint operator +(const mint& p) const {
        return mint(val + p.val);
    }
    const mint operator +(ll p) const {
        return mint(val + p);
    }
    const mint operator -(const mint& p) const {
        return mint(val - p.val);
    }
    const mint operator -(ll p) const {
        return mint(val - p);
    }
    const mint operator *(const mint& p) const {
        return mint(val * 1LL * p.val);  
    }
    const mint operator *(ll p) const {
        p %= MOD;
        return mint(val * 1LL * p);  
    }
    const mint operator /(const mint& p) const {
        return mint(val) * 1LL * binpow(p, MOD - 2);
    }
    const mint operator /(ll p) const {
        return mint(val) * 1LL * binpow(mint(p), MOD - 2);
    }
    mint& operator =(const mint& p) {
        val = p.val;
        return *this;
    }
    mint& operator =(ll p) {
        val = p;
        return *this;
    }
    mint& operator +=(const mint& p) {
        return *this = *this + p;
    }
    mint& operator +=(ll p) {
        return *this = *this + mint(p);
    }
    mint& operator -=(const mint& p) {
        return *this = *this - p;
    }
    mint& operator -=(ll p) {
        return *this = *this - mint(p);
    }
    mint& operator *=(const mint& p) {
        return *this = *this * p;
    }
    mint& operator *=(ll p) {
        return *this = *this * mint(p);
    }
    mint& operator /=(const mint& p) {
        return *this = *this / p;
    }
    mint& operator /=(ll p) {
        return *this = *this / mint(p);
    }
    bool operator ==(const mint& p) const {
        return val == p.val;
    }
    bool operator ==(ll p) const {
        return val == p;
    }
    bool operator !=(const mint& p) const {
        return val != p.val;
    }
    bool operator !=(ll p) const {
        return val != p;
    }
    mint binpow(mint p, ll d) const {
        d %= MOD - 1;
        mint ans(1);
        while (d) {
            if (d & 1)
                ans *= p;
            p *= p;
            d >>= 1;
        }
        return ans;
    }
    mint binpow(ll p, ll d) {
        return binpow(mint(p), d);
    }
    friend ostream &operator<<(ostream &out, mint p) {
        out << p.val;
        return out;
    }
};

const mint operator +(ll a, const mint& p) {
    return p + a;
}

const mint operator -(ll a, const mint& p) {
    return p - a;
}

const mint operator /(ll a, const mint& p) {
    return p / a;
}

const mint operator *(ll a, const mint& p) {
    return p * a;
}
