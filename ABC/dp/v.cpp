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
using mint = modint;
// 全方位木DP
int main()
{
    int n, m;
    cin >> n >> m;
    mint::set_mod(m);
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
    }

    vector<mint> dp(n, 0);

    auto dfs1 = [&](auto self, int v, int p = -1) -> void {
        dp[v] = 1;
        for (int u : g[v]) {
            if (u == p) continue;
            self(self, u, v);
            dp[v] *= dp[u]+ 1;
        }
    };

    vector<mint> ans(n, 0);
    auto dfs2 = [&](auto self, int v, int p = -1) -> void {
        ans[v] = 1;
        for (int u : g[v]) {
            ans[v] *= dp[u]+ 1;
        }
        int size = g[v].size();
        vector<mint> lft(size);
        vector<mint> rgt(size);
        for (int i = 0; i < size; i++) {
            lft[i] = rgt[i] = dp[g[v][i]] + 1;
        }
        for (int i = 1; i < size; i++) {
            lft[i] *= lft[i-1];
        }
        for (int i = size-2; i >= 0; i--) {
            rgt[i] *= rgt[i+1];
        }
        for (int i = 0; i < size; i++) {
            if (g[v][i] == p) continue;
            dp[v] = 1;
            if(i) {
                dp[v] *= lft[i-1];
            }
            if(i+1 < size) {
                dp[v] *= rgt[i+1];
            }
            self(self, g[v][i], v);
        }
    };

    dfs1(dfs1, 0);
    dfs2(dfs2, 0);
    rep(i, n) {
        printf("%d\n", ans[i].val());
    }
    return 0;
}
