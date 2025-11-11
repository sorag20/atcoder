#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for(int i=0;i<x;i++)
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;

struct Edge {
    int to, cost;
    Edge(int t, int c) : to(t), cost(c) {}
};

int main()
{
    ll n;
    cin >> n;
    vector<ll> x(n);
    rep(i, n) {
        cin >> x[i];
    }
    vector<vector<Edge>> G(n);
    rep(i, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].pb(Edge(v, w));
        G[v].pb(Edge(u, w));
    }

    ll ans = 0;
    auto dfs = [&](auto&& self, int v, int p) -> ll {
        ll sum = x[v];
        for (const auto& e : G[v]) {
            if (e.to == p) continue;
            ll r = self(self, e.to, v);
            ans += abs(r) * (ll) e.cost;
            sum += r;
        }

        return sum;
    };
    dfs(dfs, 0, -1);
    cout << ans << endl;


    return 0;
}
