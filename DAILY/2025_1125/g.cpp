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

ll dist[505][505][2];

int main()
{
    //freopen("input.txt", "r", stdin);

    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin>>s[i];
    const ll INF = 1e18;
    rep(i,h)rep(j,w)rep(k,2) {
        dist[i][j][k] = INF;
    }
    queue<tuple<ll,ll,ll>> q;
    
    auto push = [&](ll u, ll v, ll k, ll d) {
        if (dist[u][v][k] != INF) return;
        dist[u][v][k] = d;
        q.emplace(u,v,k);
    };
    rep(i,h)rep(j,w) {
        if (s[i][j] == 'S') push(i,j, 0, 0);
    }
    while(q.size()) {
        auto [i,j,k] = q.front();
        q.pop();
        int d = dist[i][j][k];
        if (s[i][j] == 'G') {
            cout << d << endl;
            return 0;
        }
        rep(x,4) {
            int ni = i + dx[x];
            int nj = j + dy[x];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (s[ni][nj] == '#') continue;
            if (k == 0 && s[ni][nj] == 'x') continue;
            if (k == 1 && s[ni][nj] == 'o') continue;
            int nk = k;
            if (s[ni][nj] == '?') nk ^= 1;
            push(ni, nj, nk, d+1);
        }
    }

    cout << -1 << endl;



    return 0;
}
