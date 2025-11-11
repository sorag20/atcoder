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
using mint = modint1000000007;
//木dp
int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    rep(i, n-1) {
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    vector<vector<mint>> dp(n+1, vector<mint>(2, 0));

    auto solve = [&](auto&& solve, ll v, ll p = -1) -> void {
        dp[v][0] = 1;
        dp[v][1] = 1;
        for (auto u : g[v]) {
            if (u == p) continue;
            solve(solve, u, v);
            dp[v][0] *= dp[u][0] + dp[u][1];
            dp[v][1] *= dp[u][0];
        }
    };
    solve(solve, 0);
    mint ans = dp[0][0] + dp[0][1];
    cout << ans.val() << endl;

    return 0;
}
