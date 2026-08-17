template<class T, int DIM>
struct NDPrefixSum {
    array<ll, DIM> sz{};
    array<ll, DIM> stride{};
    vector<T> dat;

    NDPrefixSum(const array<ll, DIM>& s) : sz(s) {
        ll tot = 1;
        for (ll i = DIM - 1; i >= 0; i--) {
            stride[i] = tot;
            tot *= (sz[i] + 1);
        }
        dat.assign(tot, T());
    }

    ll id(const array<ll, DIM>& p) const {
        ll res = 0;
        for (ll i = 0; i < DIM; i++) res += p[i] * stride[i];
        return res;
    }

    void add(array<ll, DIM> p, T val) {
        for (ll i = 0; i < DIM; i++) p[i]++;
        dat[id(p)] += val;
    }

    void build() {
        array<ll, DIM> p{};
        for (ll d = 0; d < DIM; d++) {
            function<void(ll)> dfs = [&](ll dep) {
                if (dep == DIM) {
                    for (ll x = 1; x <= sz[d]; x++) {
                        p[d] = x;
                        auto q = p;
                        q[d]--;
                        dat[id(p)] += dat[id(q)];
                    }
                    return;
                }
                if (dep == d) { dfs(dep + 1); return; }
                for (p[dep] = 0; p[dep] <= sz[dep]; p[dep]++) dfs(dep + 1);
            };
            dfs(0);
        }
    }

    T query(const array<ll, DIM>& L, const array<ll, DIM>& R) const {
        for (ll i = 0; i < DIM; i++)
            if (L[i] > R[i]) return T();
        T ans = T();
        constexpr ll ALL = 1 << DIM;
        array<ll, DIM> p{};

        for (ll mask = 0; mask < ALL; mask++) {
            bool ok = true;
            for (ll i = 0; i < DIM; i++) {
                if (mask >> i & 1) {
                    if (L[i] == 0) { ok = false; break; }
                    p[i] = L[i];
                } else {
                    p[i] = R[i] + 1;
                }
            }
            if (!ok) continue;

            if (pop_cnt(mask) & 1) ans -= dat[id(p)];
            else ans += dat[id(p)];
        }
        return ans;
    }
};