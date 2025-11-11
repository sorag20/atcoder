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
struct TopologicalSort {
    vector<vector<int>> E; TopologicalSort(int N) { E.resize(N); }
    void add_edge(int a, int b) { E[a].push_back(b); }
    bool visit(int v, vector<int>& order, vector<int>& color) {
        color[v] = 1;
        for (int u : E[v]) {
            if (color[u] == 2) continue; if (color[u] == 1) return false;
            if (!visit(u, order, color)) return false;
        } order.push_back(v); color[v] = 2; return true;
    }
    bool sort(vector<int> &order) {
        int n = E.size(); vector<int> color(n);
        for (int u = 0; u < n; u++) if (!color[u] && !visit(u, order, color)) return false;
        reverse(order.begin(), order.end()); return true;
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    TopologicalSort ts(n);
    vector<vector<ll>> g(n);
    vector<ll> dp(n, 0);
    vector<int> order;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        ts.add_edge(a , b);
    }
    vector<int> order;
    ts.sort(order);
    for (int i : order) {
        for (int j : g[i]) {
            dp[j] = max(dp[j], dp[i] + 1);
        }
    }
    int ans = 0;
    for (int i : dp) {
        ans = max(ans, i);
    }
    cout << ans << endl;
    return 0;
}
