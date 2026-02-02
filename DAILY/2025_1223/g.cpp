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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, m;
    cin >> n >> m;
    vector<lP> xy_b, xy_w;
    rep(i,m) {
        ll x, y;
        char c;
        cin>>x>>y>>c;
        if (c == 'B') xy_b.pb({x, y});
        else xy_w.pb({x,y});
    }

    sort(all(xy_b));
    bool f = true;
    for (auto [x, y]: xy_w) {
        auto it = lower_bound(all(xy_b), make_pair(x, (ll)-10));
        if (it == xy_b.end()) continue;
        ll target_x = it->first;
        while (it != xy_b.end()) {
             auto nit = next(it);
            if (nit == xy_b.end() || nit->first != target_x){
                break;
            }
            it++;
        }
        ll by = it->second;
        if (y <= by) {
            f = false;
            break;
        }
    }
    if (f) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
