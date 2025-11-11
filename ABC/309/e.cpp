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
    vector<vector<ll>> g(n);
    for (ll i = 1; i < n; i++) {
        ll p; cin>> p;
        p--;
        g[p].pb(i);
    }
    vector<ll> dp(n, -1);
    rep(i,m) {
        ll x, y;
        cin >> x >> y;
        x--; 
        dp[x] = max(dp[x], y);
    }

    auto dfs = [&](auto dfs, ll v) -> void {
        for (ll u : g[v]) {
            dp[u] = max(dp[u], dp[v]-1);
            dfs(dfs, u);
        }
    };

    dfs(dfs, 0);
    ll ans = 0;
    rep(i,n) if (dp[i] != -1) ans++;
    cout << ans << endl;
    return 0;
}
