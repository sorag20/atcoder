#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <tuple>
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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin>>s[i];
    int n;
    cin>>n;
    vector<tuple<P, int>> e(n+1);
    P start, end;
    rep(i,h) {
        rep(j,w) {
            if (s[i][j] == 'S') start = {i,j};
            else if (s[i][j] == 'T') end = {i,j};
        }
    }
    map<P, int> mp;
    rep(i,n) {
        int r,c,E;
        cin>>r>>c>>E;
        r--;c--;
        e[i] = make_tuple(P{r,c}, E);
        mp[{r,c}] = i;
    }
    if (!mp.count(start)) {
        cout << "No" << endl;
        return 0;
    }
    // ゴール地点に薬を追加（エネルギー0）
    if (!mp.count(end)) {
        e[n] = make_tuple(end, 0);
        mp[end] = n;
        n++;
    }
    vector<vector<ll>> g(n);

    auto getId = [&](P coord) {
        return coord.first * w + coord.second;
    };

    auto push = [&](P coord, int d, int from_id, vector<int>& dist, queue<tuple<P, int>>& que, int E, vector<int>& dist_all) {
        if (d > E) return;
        int id = -1;
        if (mp.count(coord)) id = mp[coord];
        if (id != -1 && dist[id] != -1) return;
        else if (id != -1) dist[id] = d;
        if (s[coord.first][coord.second] == '#') return;
        int grid_id = getId(coord);
        if (dist_all[grid_id] != -1) return;
        dist_all[grid_id] = d;
        if (mp.count(coord)) {
            if (from_id != id) g[from_id].pb(id);
        }
        que.push(make_tuple(coord,d));
    };

    auto bfs = [&](int from_id) {
        vector<int> dist(n, -1);
        vector<int> dist_all(h*w, -1);
        queue<tuple<P, int>> que;
        auto [coord, E] = e[from_id];
        push(coord, 0, from_id, dist, que, E, dist_all);
        while(!que.empty()) {
            auto [ncoord, d] = que.front();
            que.pop();
            rep(j,4) {
                int ni = ncoord.first + dx[j];
                int nj = ncoord.second + dy[j];
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                push({ni,nj}, d+ 1, from_id, dist, que, E, dist_all);
            }
        }
    };
    // 全薬始点のBFS
    rep(i,n) {
        bfs(i);
    }

    vector<int> dist2(n, -1);
    queue<lP> que2;

    auto push2 = [&](int e_id, int d){
        if (dist2[e_id] != -1) return;
        dist2[e_id] = d;
        que2.push({e_id, d});
    };

     int start_id = mp[start];
     push2(start_id, 0);

     while(!que2.empty()) {
        auto[e_id, d] = que2.front();que2.pop();
        for (auto v:g[e_id]) {
            push2(v, d+1);
        }
     }
     int end_id = mp[end];
     if (dist2[end_id] != -1) cout << "Yes" << endl;
     else cout << "No" << endl;

    return 0;
}
