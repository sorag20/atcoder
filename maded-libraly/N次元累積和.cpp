template<class T>
struct NDPrefixSum {
    int dim;
    vector<int> sz;
    vector<int> stride;
    vector<T> dat;

    NDPrefixSum(const vector<int>& s) : dim((int)s.size()), sz(s), stride(dim) {
        int tot = 1;
        for (int i = dim - 1; i >= 0; i--) {
            stride[i] = tot;
            tot *= (sz[i] + 1);
        }
        dat.assign(tot, T());
    }

    int id(const vector<int>& p) const {
        int res = 0;
        for (int i = 0; i < dim; i++) res += p[i] * stride[i];
        return res;
    }

    void add(vector<int> p, T val) {
        for (int& x : p) x++;
        dat[id(p)] += val;
    }

    void build() {
        vector<int> p(dim);
        for (int d = 0; d < dim; d++) {
            function<void(int)> dfs = [&](int dep) {
                if (dep == dim) {
                    for (int x = 1; x <= sz[d]; x++) {
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

    T query(const vector<int>& L, const vector<int>& R) const {
        for (int i = 0; i < dim; i++)
            if (L[i] > R[i]) return T();
        T ans = T();
        int ALL = 1 << dim;
        vector<int> p(dim);

        for (int mask = 0; mask < ALL; mask++) {
            bool ok = true;
            for (int i = 0; i < dim; i++) {
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