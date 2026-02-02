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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,h) cin>>s[i];

    queue<tuple<ll,ll,ll>> que;
    ll INF = 100;
    vector<vector<ll>> dist(h,vector<ll> (w, INF));
    vector<vector<lP>> mp(30);
    rep(i,h)rep(j,w) {
        if (s[i][j] >= 'a' && s[i][j] <= 'z'){
            int nx = s[i][j] - 'a';
            mp[nx].pb({(ll)i,(ll)j});
        }
    }
    auto push = [&](ll d, ll u, ll v) {
        if (u < 0 || u >= h || v < 0 || v >= w) return;
        if (dist[u][v] != INF) return;
        if (s[u][v] == '#') return;
        dist[u][v] = d;
        que.push({d,u,v});
    };
    push(0,0,0);
    set<char> st;
    while(!que.empty()){
        auto [d, u, v] =que.front();
        que.pop();
        int nd = d + 1;
        if (s[u][v] >= 'a' && s[u][v] <= 'z') {
            char c = s[u][v];
            if (st.find(c) == st.end())  {
                st.insert(c);
                int moji = c - 'a';
                for (auto [nu, nv] : mp[moji]) {
                    push(nd,nu,nv);
                }
            }
        }
        rep(i,4) {
            int nx = u+dx[i];
            int ny = v+dy[i];
            push(nd,nx,ny);
        }
    }

    if (dist[h-1][w-1] == INF) cout<< -1 << endl;
    else cout <<dist[h-1][w-1]<<endl;

    return 0;
}
