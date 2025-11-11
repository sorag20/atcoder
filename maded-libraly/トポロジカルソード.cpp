struct TopologicalSort {
    vector<vector<int>> E; TopologicalSort(int N) { E.resize(N); }
    void add_edge(int a, int b) { E[a].push_back(b); }
    bool visit(int v, vector<int>& order, vector<int>& color) {
        color[v] = 1;
        for (int u : E[v]) {
            if (color[u] == 2) continue; if (color[u] == 1) return false;
            if (!visit(u, order, color)) return false;
        } order.push_back(v); color[v] = 2; return true;
    }
    bool sort(vector<int> &order) {
        int n = E.size(); vector<int> color(n);
        for (int u = 0; u < n; u++) if (!color[u] && !visit(u, order, color)) return false;
        reverse(order.begin(), order.end()); return true;
    }
};



/* こんな感じで使う
    TopologicalSort ts(n);
    vector<vector<ll>> g(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        ts.add_edge(a , b);
    }
    vector<int> order;
    ts.sort(order);
*/
