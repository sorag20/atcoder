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
    //freopen("input.txt", "r", stdin);

    ll n, m;
    cin >> n >> m;
    ll n2 = n * 2;
    TopologicalSort ts(n2);
    vector<vector<ll>> g(n2);
    rep(i,m) {
        ll k;
        cin >> k;
        vector<ll> a(k);
        rep(i, k) {
            cin >> a[i];
            a[i]--;
        }
        for (int j = k - 1; j > 0; j--) {
            g[a[j]].pb(a[j - 1]);
            ts.add_edge(a[j], a[j - 1]);
        }
    }
    vector<int> order;
    ts.sort(order);
    if (order.size() == n2) cout << "Yes" << endl;
    else {
        cout << "No" << endl;
    }

    return 0;
}
