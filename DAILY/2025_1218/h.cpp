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

// ダイクストラ
int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, m;
    cin >> n >> m;
    vector<vector<tuple<ll, ll, ll>>> g(n);
    {
        rep(i,m) {
            ll a,b,c;
            cin>> a>> b>> c;
            a--;b--;
            g[a].pb({b, c, i+1});
            g[b].pb({a, c, i+1});
        }
    }
    ll const INF = 1e18;
    vector<ll> dist(n, INF);
    priority_queue<lP, vector<lP>, greater<lP>> que;

    que.push({0, 0});
    dist[0] = 0;

    vector<ll> ans(n);
    while(!que.empty()) {
        auto [d, to] = que.top();que.pop();
        if (dist[to] != d) continue;

        for (auto[b, c, id]: g[to]) {
            ll nd = d + c;
            if (dist[b] <= nd) continue;
            dist[b] = nd;
            ans[b] = id;
            que.push({nd, b});
        }
    }

    for (int i = 1;i < n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;




    return 0;
}
