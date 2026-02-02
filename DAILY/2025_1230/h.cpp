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
using mint = modint998244353;

mint dp[2005][2005][2];
int main()
{
    //freopen("input.txt", "r", stdin);

    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    s--;t--;x--;
    vector<vector<int>> g(n);
    rep(i,m) {
        int u, v;
        cin>> u>>v;
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dp[0][s][0] = 1;
    for (int i = 0;i < k;i++) {
        rep(j,n) {
            rep(l, 2) {
                for (auto u:g[j]) {
                    int nl = l;
                    if (u == x) nl ^= 1;
                    dp[i + 1][u][nl] += dp[i][j][l];
                }
            }
        }
    }
    cout << dp[k][t][0].val() << endl;


    return 0;
}
