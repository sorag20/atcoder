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
    vector<vector<lP>> g(n);
    map<lP, ll> w;
    rep(i,m) {
        ll a, b, W;
        cin >> a >> b >> W;
        a--; b--;
        g[a].emplace_back(b, W);
        g[b].emplace_back(a, W);
    }

    ll ans = 2e18;
    auto dfs = [&](auto dfs, ll v, ll x, vector<bool> used) -> void {
        used[v] = true;
        if (v == n-1) {
            ans = min(ans, x);
            return;
        }
        for (auto [nv, w] : g[v]) {
            if (used[nv]) continue;
            dfs(dfs, nv, x ^ w, used);
        }
    };

    dfs(dfs, 0, 0, vector<bool>(n, false));

    cout << ans << endl;


    return 0;
}
