vector<bool> visited(n, false);
auto dfs = [&](auto dfs, ll v) -> void {
    visited[v] = true;
    for (ll u : g[v]) {
        if (!visited[u]) {
            dfs(dfs, u);
        }
    }
};
