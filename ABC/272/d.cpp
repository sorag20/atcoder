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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,m;
    cin >> n >> m;
    vector<lP> g;
    for(int i = -n; i<= n; i++)
 {
    for(int j = -n; j<= n; j++) {
        if (i*i+j*j == m) g.emplace_back(i,j);
    }
 }
    const ll INF = 1001001001;
    vector dist(n, vector<ll>(n, INF));
    queue<lP> que;
    auto push = [&] (ll s, ll t, ll distance) {
        if (s < 0 || t < 0 || s >= n || t >= n) return;
        if (dist[s][t] != INF) return;
        dist[s][t] = distance;
        que.emplace(s,t);
    };
    push(0,0,0);
    while(!que.empty()) {
        auto [i,j] = que.front();que.pop();
        for (auto[s,t]: g) {
            ll ni = i + s;
            ll nj = j + t;
            push(ni, nj, dist[i][j] + 1);
        }
    }
    rep(i,n){
        rep(j,n) {
            if (dist[i][j] == INF) cout << -1 << ' ';
            else cout <<dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
