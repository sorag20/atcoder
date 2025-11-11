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

ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
int main()
{
    //freopen("input.txt", "r", stdin);

    ll h, w;
    cin >> h>> w;
    vector<string> s(h), t(h);
    rep(i,h) {
        cin >> s[i];
    }
    // {座標、座標、今どちらの面にいるか}
    queue<tuple<ll, ll, ll>> que;
    vector<vector<vector<ll>>> dist(h, vector<vector<ll>>(w, vector<ll>(2, -1)));
    tuple<ll, ll, ll> start = {0, 0, 0};
    P goal = {0, 0};
    rep(i,h) {
        rep(j,w) {
            if (s[i][j] == 'S') start = {i, j, 0};
            if (s[i][j] == 'G') goal = {i, j};
        }
    }
    que.push(start);
    dist[get<0>(start)][get<1>(start)][0] = 0;
    while(!que.empty()) {
        auto [x, y, f] = que.front();
        que.pop();
        rep(i,4) {
            if (x + dx[i] < 0 || x + dx[i] >= h || y + dy[i] < 0 || y + dy[i] >= w) continue;
                // 空いたドアの面
                if (f == 0) {
                    if (s[x + dx[i]][y + dy[i]] == '.' || s[x + dx[i]][y + dy[i]] == 'S' || s[x + dx[i]][y + dy[i]] == 'o' || s[x + dx[i]][y + dy[i]] == 'G') {
                        if (dist[x + dx[i]][y + dy[i]][0] != -1) continue;
                        que.push({x + dx[i], y + dy[i], 0});
                        dist[x + dx[i]][y + dy[i]][0] = dist[x][y][0] + 1;
                    } else if (s[x + dx[i]][y + dy[i]] == '?') {
                        if (dist[x + dx[i]][y + dy[i]][1] != -1) continue;
                            que.push({x + dx[i], y + dy[i], 1});
                            dist[x + dx[i]][y + dy[i]][1] = dist[x][y][0] + 1;
                    }
                } else {
                    if (s[x + dx[i]][y + dy[i]] == '.' || s[x + dx[i]][y + dy[i]] == 'S' || s[x + dx[i]][y + dy[i]] == 'x'|| s[x + dx[i]][y + dy[i]] == 'G') {
                        if (dist[x + dx[i]][y + dy[i]][1] != -1) continue;
                        que.push({x + dx[i], y + dy[i], 1});
                        dist[x + dx[i]][y + dy[i]][1] = dist[x][y][1] + 1;
                    } else if (s[x + dx[i]][y + dy[i]] == '?') {
                        if (dist[x + dx[i]][y + dy[i]][0] != -1) continue;
                            que.push({x + dx[i], y + dy[i], 0});
                            dist[x + dx[i]][y + dy[i]][0] = dist[x][y][1] + 1;
                    }
                }
        }
    }

    if (dist[goal.first][goal.second][0] != -1) {
        if (dist[goal.first][goal.second][1] != -1) {
            cout << min(dist[goal.first][goal.second][0], dist[goal.first][goal.second][1]) << endl;
        } else {
            cout << dist[goal.first][goal.second][0] << endl;
        }
    } else {
        if (dist[goal.first][goal.second][1] != -1) {
            cout << dist[goal.first][goal.second][1] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
