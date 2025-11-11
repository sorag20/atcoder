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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll h, w, s, t;
    cin >> h >> w >> s >> t;
    s--; t--;
    ll n;
    cin >> n;
    vector<vector<ll>> y_x_for_r(h), y_x_for_l(h);
    vector<vector<ll>> x_y_for_u(w), x_y_for_d(w);
    rep(i,n) {
        ll y, x;
        cin >> y >> x;
        x--; y--;
        y_x_for_r[y].pb(x);
        y_x_for_l[y].pb(-x);
        x_y_for_d[x].pb(y);
        x_y_for_u[x].pb(-y);
    }

    for (auto &v : y_x_for_r) sort(all(v));
    for (auto &v : y_x_for_l) sort(all(v));
    for (auto &v : x_y_for_u) sort(all(v));
    for (auto &v : x_y_for_d) sort(all(v));

    auto func = [](vector<ll> &v, ll i, ll j, ll l, bool is_reverse, ll r) -> ll {
        auto it = lower_bound(all(v), j);
        if (it == v.end()) {
            if (is_reverse) return max(-j - l, r + 1);
            return min(j + l, r - 1);
        }
        ll pos = *it;
        if (is_reverse) return max(-j - l, -pos + 1);
        return min(j + l, pos - 1);
    };

    ll q;
    cin >> q;
    while (q--) {
        char c;
        ll l;
        cin >> c >> l;
        if (c == 'U') {
            if (x_y_for_u[t].empty()) {
                s = max(s - l, 0LL);
            } else {
                s = func(x_y_for_u[t], t, -s, l, true, -1);
            }
        } else if (c == 'D') {
            if (x_y_for_d[t].empty()) {
                s = min(s + l, h - 1);
            } else {
                s = func(x_y_for_d[t], t, s, l, false, h);
            }
        } else if (c == 'L') {
            if (y_x_for_l[s].empty()) {
                t = max(t - l, 0LL);
            } else {
                t = func(y_x_for_l[s], s, -t, l, true, -1);
            }
        } else if (c == 'R') {
            if (y_x_for_r[s].empty()) {
                t = min(t + l, w - 1);
            } else {
                t = func(y_x_for_r[s], s, t, l, false, w);
            }
        }
        cout << s + 1 << " " << t + 1 << endl;
    }

    return 0;
}
