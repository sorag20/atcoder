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
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    rep(i,n-1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<ll> ans;
    ll start = 0;
    rep(i,n) {
        if (g[i].size() == 1) {
            start = i;
            break;
        }
    }
    auto dfs = [&](auto dfs, ll v, ll p = 0, ll cnt = 0) -> void {
        if (cnt % 3 == 1) {
            ans.pb(g[v].size());
        }
        for (auto nv : g[v]) {
            if (nv == p) continue;
            dfs(dfs, nv, v, cnt+1);
        }
    };
    dfs(dfs, start);
    sort(all(ans));

    for (auto nv : ans) {
        cout << nv << ' ';
    }

    return 0;
}
