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

struct edge {
    ll a, b, w;
    edge() {}
    edge(ll a, ll b, ll w) : a(a), b(b), w(w) {}
};
int main()
{
    ll n, m , k;
    cin >> n >> m >> k;
    vector<edge> es;
    rep (i,m) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        es.emplace_back(u, v, w);
    }
    const ll INF = 1e18;
    ll ans = INF;
    auto dfs = [&](auto dfs, ll v, vector<ll> used) -> void {
        if ((int) used.size() == (int) n-1) {
            ll cnt = 0;
            dsu d(n);
            bool flag = true;
            for (auto ei : used) {
                auto e = es[ei];
                if (d.same(e.a, e.b)) flag = false;
                d.merge(e.a, e.b);
                cnt = (cnt + e.w) % k;
            }
            if (flag) ans = min(ans, cnt);
            return;
        }
        if (v == m) return;
        dfs(dfs, v+1, used);
        used.pb(v);
        dfs(dfs, v+1, used);
    };
    dfs(dfs, 0, {});
    cout << ans << endl;
    return 0;
}
