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
#define TU tuple<ll, int, int>
using namespace std;
using namespace atcoder;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    ll h, w, x, p, q;
    cin >> h >> w >> x >> p >> q;
    p--; q--;
    vector<vector<ll>> s(h, vector<ll>(w));
    rep(i, h) {
        rep(j, w) {
            ll X;
            cin >> X;
            s[i][j] = X;
        }
    }
    ll ans = s[p][q]; s[p][q] = 0;
    priority_queue<TU, vector<TU>, greater<TU>> queue;
    vector<vector<bool>> used(h, vector<bool>(w, false));

    auto push = [&](int Y, int X) {
        rep(i, 4) {
            int ny = Y + dy[i];
            int nx = X + dx[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (used[ny][nx]) continue;
            used[ny][nx] = true;
            queue.emplace(s[ny][nx], ny, nx);
        }
    };
    push(p, q);

    while(!queue.empty()) {
        auto [c, Y, X] = queue.top(); queue.pop();
        if (c > (ans-1)/x) break;
        ans += c;
        push(Y, X);
    }
    cout << ans << endl;

    return 0;
}
