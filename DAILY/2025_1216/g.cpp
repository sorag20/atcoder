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
    ll const INF = 1e18;

    ll h, w;
    cin>>h>>w;
    vector<vector<ll>> a(h, vector<ll> (w));
    vector<vector<ll>> b(h, vector<ll> (w));
    rep(i,h)rep(j,w) cin>>a[i][j];
    rep(i,h)rep(j,w) cin>>b[i][j];
    queue<vector<vector<ll>>> que;
    map<vector<vector<ll>>, ll> dist;

    auto push = [&](vector<vector<ll>> now, ll d) {
        if (dist.count(now)) return;
        dist[now] = d;
        que.push(now);
    };

    push(a, 0);

    while(!que.empty()) {
        auto x = que.front();
        que.pop();
        ll d = dist[x];
        rep(i,h-1) {
            auto na = x;
            swap(na[i], na[i+1]);
            push(na, d+1);
        }
        rep(j, w-1) {
            auto na = x;
            rep(i,h) {
                swap(na[i][j], na[i][j+1]);
            }
            push(na,d+1);
        }
    }


    if (!dist.count(b)) cout << -1 << endl;
    else cout << dist[b] << endl;

    return 0;
}
