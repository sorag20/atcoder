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
    int to, cost;
};

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, m, k;
    cin >> n >> m >> k;
    int n2 = n*2;
    vector<vector<Edge>> g(n2);
    rep(i,m) {
        int a, b, c;
        cin>> a >> b>> c;
        a--; b--;
        if (c == 1) {
            g[a].pb((Edge){b, 1});
            g[b].pb((Edge){a, 1});
        } else {
            g[n + a].pb((Edge){n+b, 1});
            g[n + b].pb((Edge){n+a, 1});
        }
    }
    rep(i,k) {
        int v;
        cin>>v;
        v--;
        g[v].pb((Edge){n+v, 0});
        g[n + v].pb((Edge){v, 0});
    }

    const int INF = 1001001001;
    vector<int> dist(n2, INF);
    deque<P> q;
    dist[0] = 0;
    q.eb(0,0);
    while(q.size()) {
        auto [d, v] = q.front();
        q.pop_front();
        if (dist[v] != d) continue;
        for(Edge e: g[v]) {
            int nd = d + e.cost;
            if (nd >= dist[e.to]) continue;
            dist[e.to] = nd;
            if(e.cost) q.eb(nd, e.to);
            else q.emplace_front(nd, e.to);
        }
    }
    int ans = min(dist[n - 1], dist[2* n - 1]);
    if (ans == INF) cout << -1 << endl;
    else cout << ans <<endl;

    return 0;
}
