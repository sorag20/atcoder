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

int main()
{
    ll n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    map<ll, set<ll>> x_map, y_map;
    rep(i, n){
        ll x, y;
        cin >> x >> y;
        x_map[x].insert(y);
        y_map[y].insert(x);
    }
    ll ans = 0;

    rep(i, m) {
        char d;
        ll c;
        ll x = sx, y = sy;
        cin >> d >> c;
        if (d == 'U') y += c;
        if (d == 'D') y -= c;
        if (d == 'L') x -= c;
        if (d == 'R') x += c;
        bool is_x_swap = false;
        bool is_y_swap = false;
        if (sx > x) {
            swap(sx, x);
            is_x_swap = true;
        }
        if (sy > y) {
            swap(sy, y);
            is_y_swap = true;
        }
        while(1) {
            if (d == 'U' || d == 'D') {
                auto it = x_map[x].lower_bound(sy);
                if (it == x_map[x].end()) {
                    break;
                }
                if (*it > y) {
                    break;
                }
                y_map[*it].erase(x);
                x_map[x].erase(it);
                ans++;
            } else {
                auto it = y_map[y].lower_bound(sx);
                if (it == y_map[y].end()) {
                    break;
                }
                if (*it > x) {
                    break;
                }
                x_map[*it].erase(y);
                y_map[y].erase(it);
                ans++;
            }
        }
        if (is_x_swap) {
            swap(sx, x);
        }
        if (is_y_swap) {
            swap(sy, y);
        }
        sx = x;
        sy = y;
    }
    cout << sx << " " << sy << " " << ans << endl;
    
    return 0;
}
