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
const ll INF = 1e18;

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, a,b,c;
    cin >> n >> a >> b >> c;
    vector<vector<ll>> d(n, vector<ll>(n, 0));
    rep(i,n)rep(j,n) {
        cin >> d[i][j];
    }
    auto solve = [&](ll sv, ll x, ll y) {
        vector<ll> dist(n, INF);
        priority_queue<lP, vector<lP>, greater<lP>> pq;
        vector<bool> used(n, false);
        pq.push({0, sv});
        while (!pq.empty()) {
            auto [cost, v] = pq.top();
            pq.pop();
            if (used[v]) continue;
            used[v] = true;
            dist[v] = cost;
            for (int u = 0; u < n; u++) {
                ll new_cost = cost + d[v][u] * x + y;
                if (new_cost < dist[u]) {
                    dist[u] = new_cost;
                    pq.push({new_cost, u});
                }
            }
        }
        return dist;
    };

    auto dist_a = solve(0, a, 0);
    auto dist_b = solve(n-1, b, c);

    ll ans = INF;
    for (int i = 0; i < n; i++) {
        if (dist_a[i] == INF || dist_b[i] == INF) continue;
        ans = min(ans, dist_a[i] + dist_b[i]);
    }
    cout << ans << endl;


    return 0;
}
