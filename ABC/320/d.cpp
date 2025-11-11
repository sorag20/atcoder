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
    ll n, m;
    cin >> n >> m;
    dsu uf(n);
    vector<vector<ll>> g(n);
    map<lP, lP> mp;
    rep(i, m) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        a--;
        b--;
        uf.merge(a, b);
        g[a].pb(b);
        g[b].pb(a);
        mp[{a, b}] = {x, y};
        mp[{b, a}] = {-x, -y};
    }
    const ll INF = 1e18;

    vector<lP> coordinate(n, {INF, INF});

    auto dfs = [&](auto dfs, ll v, ll p, ll x, ll y)  -> void{
        coordinate[v] = {x, y};
        for (auto to : g[v]) {
            if (to == p) continue;
            if (coordinate[to].first == INF) {
                dfs(dfs, to, v, mp[{v, to}].first + x, mp[{v, to}].second + y);
            }
        }
    };

    dfs(dfs, 0, INF, 0, 0);

    for (int i = 0; i < n; i++) {
        if (coordinate[i].first == INF) {
            cout << "undecidable" << endl;
        } else {
            cout << coordinate[i].first << " " << coordinate[i].second << endl;
        }
    }
    return 0;
}
