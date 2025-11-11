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
    ll n, k;
    cin >> n>> k;
    vector<vector<ll>> g(n);
    rep(i,n-1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<ll> v0(k);
    vector<bool> selected(n);
    rep(i,k) {
        cin>>v0[i];
        v0[i]--;
        selected[v0[i]] = true;
    }
    vector<ll> num(n);
    auto dfs = [&](auto self, ll v, ll p = -1) -> ll {
        if (selected[v]) num[v]++;
        for (ll u : g[v]) {
            if (u == p) continue;
            num[v] += self(self, u, v);
        }
        return num[v];
    };
    dfs(dfs, v0[0]);
    ll ans = 0;
    rep(i,n) {
        if (num[i] != 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
