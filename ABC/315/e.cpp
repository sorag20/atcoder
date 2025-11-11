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
    rep(i,n) {
        ll c; cin >> c;
        rep(j,c) {
            ll a; cin >> a;
            a--;
            g[i].pb(a);
        }
    }
    vector<ll> visited(n, 0);
    vector<ll> ans;
    auto dfs = [&](auto dfs, ll v) -> void {
        visited[v] = 1;
        for (ll u : g[v]) {
            if (visited[u] == 0) {
                dfs(dfs, u);
            }
        }
        ans.pb(v);
    };
    dfs(dfs, 0);
    ans.pop_back();
    for(auto c : ans) cout << c+1 << " ";
    cout << endl;
    
    return 0;
}
