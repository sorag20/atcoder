ll const INF = 1e18;
vector<ll> dist(n, INF);
priority_queue<lP, vector<lP>, greater<lP>> que;

que.push({0, 0});
dist[0] = 0;

while(!que.empty()) {
    auto [d, to] = que.top();que.pop();
    if (dist[to] != d) continue;
    for (auto[b, c]: g[to]) {
        ll nd = d + c;
        if (dist[b] <= nd) continue;
        dist[b] = nd;
        que.push({nd, b});
    }
}

for (int i = 1;i < n;i++){
    cout << dist[i] << " ";
}
cout << endl;