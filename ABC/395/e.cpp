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

int main()
{
    ll n, m, x;
    cin >> n >> m >> x;
    vector<vector<ll>> g(n*2);
    rep(i,m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a*2].pb(b*2);
        g[b*2+1].pb(a*2+1);
    }
    priority_queue<lP, vector<lP>, greater<lP>> q;
    const ll INF = 1e18;
    vector<ll> dist(n*2, INF);
    auto push = [&](ll v, ll d) {
        if (dist[v] <= d) return;
        dist[v] = d;
        q.push({d, v});
    };

    push(0, 0);
    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();
        if (dist[v] != d) continue;
        for (auto nv : g[v]) {
            push(nv, d + 1);
        }
        push(v^1, d + x);
    }
    cout << min(dist[n*2-1], dist[n*2-2]) << endl;

    return 0;
}
