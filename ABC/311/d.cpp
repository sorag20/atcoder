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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep (i,n) cin >> s[i];
    vector<vector<bool>> used(n, vector<bool>(m, false));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<lP> q;
    q.push({1, 1});
    used[1][1] = true;
    visited[1][1] = true;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] != '#') {
                used[nx][ny] = true;
                nx += dx[i];
                ny += dy[i];
            }
            nx -= dx[i];
            ny -= dy[i];
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    ll ans = 0;
    rep(i, n) rep(j, m) {
        if (used[i][j]) ans++;
    }
    cout << ans << endl;
    return 0;
}
