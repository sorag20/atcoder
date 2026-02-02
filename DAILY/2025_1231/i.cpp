#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for(int i=0;i<x;i++)
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    vector<lP> e(n-1);
    vector<vector<ll>> g(n);
    rep(i,n-1) {
        ll u, v;
        cin >> u >> v;
        u--;v--;
        e[i] = {u,v};
        g[u].pb(v);
        g[v].pb(u);
    }

    // 部分木をin, out で表現する。outは半開になる
    vector<ll> in(n), out(n);

    ll id = 0;
    auto dfs = [&](auto dfs, ll v, ll p = -1) ->void {
        in[v] = id++;
        for (auto u: g[v]) {
            if (u != p) dfs(dfs, u, v);
        }
        out[v] = id;
    };

    dfs(dfs, 0);

    rep(i,n) {
        cout << in[i] << "";
    }
    cout << endl;

    rep(i,n) {
        cout << out[i] << "";
    }
    cout << endl;

    fenwick_tree<ll> f(n);

    rep(i,n) {
        f.add(i, 1);
    }
    ll q;
    cin>>q;
    rep(i,q) {
        int t; cin>>t;
        if (t == 1) {
            ll x, w;
            cin>>x>>w;
            x--;
            f.add(in[x], w);
        } else {
            ll y; cin>>y;
            y--;
            auto [u, v] = e[y];
            if (in[u] < in[v]) swap(u,v);
            ll sum_u = f.sum(in[u], out[u]);
            ll sum_v = f.sum(0, n) - sum_u;
            cout << abs(sum_u - sum_v) << endl;
         }
    }
 
    return 0;
}
