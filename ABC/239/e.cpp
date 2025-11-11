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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
//　木
int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, q;
    cin >> n >> q;
    vector<ll> x(n);
    rep(i, n) {
        cin >> x[i];
    }
    ll max_k = 20;
    vector<vector<ll>> g(n);
    rep(i,n-1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<vector<ll>> ans(n);

    auto dfs = [&](auto self, ll v, ll p) -> void {
        ans[v].pb(x[v]);
        for (auto u : g[v]) {
            if (u == p) continue;
            self(self, u, v);
            for (auto a : ans[u]) {
                ans[v].pb(a);
            }
        }
        sort(gall(ans[v]));
        if (ans[v].size() > max_k) {
            ans[v].resize(max_k);
        }
    };
    dfs(dfs, 0, -1);


    rep(i,q) {
        ll v, k;
        cin >> v >> k;
        v--;
        cout << ans[v][k-1]<< endl;
    }

    return 0;
}
