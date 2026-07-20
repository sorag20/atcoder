// 検出
vl flag(N);
bool ok = false;
rep(sv, N) {
    if (flag[sv] == 0) {
        auto dfs = [&](auto dfs, ll v) -> bool {
            if (flag[v]) {
                return flag[v] == 1;
            }
            flag[v] = 1;
            for (ll u:to[v]) {
                if (dfs(dfs,u)) return true;
            }
            flag[v] = 2;
            return false;
        };
        if (dfs(dfs,sv)) {
            out("Yes")
            ok = true;
            break;
        }
    }
}
if (!ok)out("No")

// サイクルの頂点取得(無向辺)
vb visited(n);
set<ll> cycles;
auto dfs = [&](auto dfs, ll v, ll p = -1) ->ll {
    if (visited[v]) {
        return v;
    }
    visited[v] = true;
    for (auto u:g[v]) {
        if (u == p) continue;
        ll r = dfs(dfs, u, v);
        if (r == -1) continue;
        cycles.insert(v);
        if (v == r) return -1;
        return r;
    }
    return -1;
};
dfs(dfs, 0);

// サイクルの頂点取得(有向辺)
vl state(n, 0);
vl stk;
set<ll> cycles;

auto dfs = [&](auto dfs, ll v) -> void {
    state[v] = 1;
    stk.pb(v);
    for (auto u : g[v]) {
        if (state[u] == 0) {
            dfs(dfs, u);
        } else if (state[u] == 1) {
            for (ll i = (ll)stk.size() - 1; i >= 0; i--) {
                cycles.insert(stk[i]);
                if (stk[i] == u) break;
            }
        }
    }
    stk.pob();
    state[v] = 2;
};

rep(v, n) if (state[v] == 0) dfs(dfs, v);