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
// 頂点倍化

struct Edge {
    ll to;
    ll cost;
};
int main()
{
    ll n,m;
    cin >> n >> m;
    vector<vector<Edge>> G(n);
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].pb({b, c});
    }
    const ll MAX_VERTICES = 1<< 10;
    vector<bool> visited(MAX_VERTICES * n, 0);
    queue<ll> que;
    auto push = [&](ll v, ll cost) {
        ll idx = v*MAX_VERTICES + cost;
        if (visited[idx]) return;
        visited[idx] = true;
        que.push(idx);
    };
    push(0, 0);
    while (!que.empty()) {
        ll idx = que.front();
        que.pop();
        ll v = idx / MAX_VERTICES;
        ll x = idx % MAX_VERTICES;
        for (auto e : G[v]) {
            push(e.to, x^e.cost);
        }
    }
    rep(i, MAX_VERTICES) {
        if (visited[(n - 1)* MAX_VERTICES + i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;


    return 0;
}
