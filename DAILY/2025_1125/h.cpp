#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
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

struct Edge {
    ll a, b, c;
    Edge(ll a, ll b, ll c) : a(a), b(b), c(c){}
};



int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, m, k;
    cin>> n>>m>>k;
    vector<Edge> g;
    rep(i,m) {
        ll a, b, c;
        cin>>a>>b>>c;
        a--;b--;
        g.eb(a,b,c);
    }

    const ll INF = 1e18;
    vector<ll> dist(n, INF);
    dist[0] = 0;
    rep(i,k) {
        ll e; cin>>e;
        e--;
        auto[a,b,c] = g[e];
        dist[b] = min(dist[b], dist[a] + c);
    }
    if (dist[n-1] == INF) cout <<-1 << endl;
    else cout << dist[n-1] << endl;

    return 0;
}
