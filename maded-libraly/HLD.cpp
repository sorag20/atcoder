// nはグローバル上に宣言するため、int main()内では定義しないよう気をつける。
ll n;
vvc<lP> g; // g[v] = {(to, edge_id), ...}
vl par;    // par[v]   = vの親頂点(rootは-1)
vl depth;  // depth[v] = 根からの深さ
vl sz;     // sz[v]    = vを根とする部分木のサイズ
vl heavy;  // heavy[v] = vの重い子(部分木サイズ最大の子、無ければ-1)
vl head;   // head[v]  = vが属するHLDチェインの先頭頂点
vl in;     // in[v]    = vのHLD上の並び順(Fenwick Treeのindex)
vl rev_in; // rev_in[in[v]] = v (inの逆引き。レベル祖先クエリで使う)
vl edge_child; // edge_child[i] = 辺i(0-indexed)の子側の頂点

void hld_build(int root) {
    par.assign(n, -1); depth.assign(n, 0); sz.assign(n, 1); heavy.assign(n, -1);
    edge_child.assign(n - 1, -1);

    vector<ll> order; order.reserve(n);
    vector<char> visited(n, 0);
    queue<ll> q; q.push(root); visited[root] = 1;
    while (!q.empty()) {
        ll v = q.front(); q.pop();
        order.pb(v);
        for (auto [to, id] : g[v]) {
            if (!visited[to]) {
                visited[to] = 1;
                par[to] = v;
                depth[to] = depth[v] + 1;
                edge_child[id] = to;
                q.push(to);
            }
        }
    }
    drep(i, (ll)order.size()) {
        ll v = order[i];
        ll maxsz = -1;
        for (auto [to, id] : g[v]) {
            if (to == par[v]) continue;
            sz[v] += sz[to];
            if (sz[to] > maxsz) { maxsz = sz[to]; heavy[v] = to; }
        }
    }

    head.assign(n, -1); in.assign(n, -1); rev_in.assign(n, -1);
    int timer = 0;
    vector<lP> st; st.pb({root, root}); // (v, head)
    while (!st.empty()) {
        auto [v, h] = st.back(); st.pob();
        head[v] = h;
        in[v] = timer;
        rev_in[timer] = v;
        timer++;
        if (heavy[v] != -1) {
            for (auto [to, id] : g[v]) {
                if (to == par[v] || to == heavy[v]) continue;
                st.pb({to, to});
            }
            st.pb({heavy[v], h});
        }
    }
}


ll hld_lca(ll u, ll v) {
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        u = par[head[u]];
    }
    return depth[u] < depth[v] ? u : v; // 深さが浅い方がLCA
}

// vからk個上の祖先を返す(レベル祖先クエリ)。存在しなければ-1
ll hld_la(ll v, ll k) {
    ll target_depth = depth[v] - k;
    if (target_depth < 0) return -1;
    while (depth[head[v]] > target_depth) {
        v = par[head[v]];
    }
    return rev_in[in[v] - (depth[v] - target_depth)];
}

// パスs-tにおけるi番目(0-indexed, sが0番目)の頂点を返す。存在しなければ-1
ll hld_jump(ll s, ll t, ll i) {
    ll l = hld_lca(s, t);
    ll d1 = depth[s] - depth[l]; // sからlcaまでの距離
    ll d2 = depth[t] - depth[l]; // lcaからtまでの距離
    if (i < 0 || i > d1 + d2) return -1;
    if (i <= d1) return hld_la(s, i);
    return hld_la(t, d1 + d2 - i);
}

fenwick_tree<ll> fw(0);

ll hld_dist(int u, int v) {
    ll res = 0;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        res += fw.sum(in[head[u]], in[u] + 1);
        u = par[head[u]];
    }
    if (depth[u] > depth[v]) swap(u, v); // u : 浅い方(LCA)
    res += fw.sum(in[u] + 1, in[v] + 1); // uの上向き辺は含めない
    return res;
}

//hld_distを使う場合は、以下をhld_buildの後に行う。
fw = fenwick_tree<ll>(n);
rep(v,n) if (par[v] != -1) fw.add(in[v], 1);