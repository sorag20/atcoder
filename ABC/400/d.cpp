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
#define TU tuple<ll, ll, ll>
using namespace std;
using namespace atcoder;

const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};
int main()
{
    ll h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) {
        cin >> s[i];
    }
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;

    priority_queue<TU, vector<TU>, greater<TU>> q;
    const ll INF = 1e18;
    vector<vector<ll>> dist(h, vector<ll>(w, INF));
    auto push = [&](ll Y, ll X, ll d) {
        if (dist[Y][X] <= d) return;
        dist[Y][X] = d;
        q.push({d, Y, X});
    };
    push(a, b, 0);
    while (!q.empty()) {
        auto [d, Y, X] = q.top();
        q.pop();
        if (dist[Y][X] != d) continue;
        for (ll i = 0; i < 4; i++) {
            ll ny = Y + dy[i];
            ll nx = X + dx[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (s[ny][nx] == '.') push(ny, nx, d);
            else push(ny, nx, d + 1);
            ll ny_2 = Y + dy[i] * 2;
            ll nx_2 = X + dx[i] * 2;
            if (nx_2 < 0 || nx_2 >= w || ny_2 < 0 || ny_2 >= h) continue;
            push(ny_2, nx_2, d +1);
        }
    }

    ll ans = dist[c][d];

    cout << ans << endl;
    return 0;
}
