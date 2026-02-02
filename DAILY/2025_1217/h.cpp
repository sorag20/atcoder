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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<ll> x(n);
    rep(i,n) cin>>x[i];
    vector<vector<lP>> g(n);
    rep(i,n-1) {
        ll u, v, w;
        cin >> u >> v >>w;
        u--;v--;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    ll ans = 0;
    auto dfs = [&](auto dfs, ll u, ll p = -1) -> ll {
        ll total = x[u];
        for (auto[to, w]: g[u]) {
            if (to == p) continue;
            ll res = dfs(dfs, to, u);
            ans += abs(res) * w;
            total += res;
        }

        return total;
    };

    dfs(dfs, 0);
    cout << ans << endl;
    return 0;
}
