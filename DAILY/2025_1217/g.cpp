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

    ll n,k;
    cin >> n >> k;
    vector<vector<ll>> g(n);
    rep(i,n-1) {
        ll a, b;
        cin>>a>>b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    unordered_set<ll> st;
    ll start = -1;
    rep(i,k) {
        ll v; cin>>v;
        v--;
        start = v;
        st.insert(v);
    }

    vector<ll> cost(n);
    auto dfs = [&](auto dfs, ll u, ll p = -1) -> ll {
        for (auto v: g[u]) {
            if (v == p) continue;
            ll res = dfs(dfs, v, u);
            cost[u] += res;
        }
        ll plus = st.find(u) == st.end() ? 0 : 1;
        cost[u] += plus;
        return cost[u];
    };

    dfs(dfs, start);
    ll ans = 0;
    rep(i,n) {
        if (cost[i] != 0) ans++;
    }

    cout << ans << endl;

    return 0;
}
