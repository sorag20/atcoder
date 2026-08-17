template<class T>
struct PrefixSum2D {
    ll h, w;
    vvc<T> dat;
    PrefixSum2D(ll h_, ll w_) : h(h_), w(w_), dat(h_ + 1, vc<T>(w_ + 1, T())) {}
    void add(ll i, ll j, T val) {
        dat[i+1][j+1] += val;
    }

    void build() {
        rep(i, h+1) rep(j, w) dat[i][j+1] += dat[i][j];
        rep(j, w+1) rep(i, h) dat[i+1][j] += dat[i][j];
    }

    T query(ll i1, ll j1, ll i2, ll j2) const {
        if (i1 > i2 || j1 > j2) return T();
        return dat[i2+1][j2+1] - dat[i1][j2+1] - dat[i2+1][j1] + dat[i1][j1];
    }
};