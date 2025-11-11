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

    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    ll ans = 0;
    ll const INF = 1e18;
    ll x_min = INF;
    ll x_max = -INF;
    vector<ll> dist_pairs;

    rep(i, n) {
        cin >> x[i];
        x_min = min(x_min, x[i]);
        x_max = max(x_max, x[i]);
    }
    sort(all(x));
    for (int i = 0; i < n - 1; i++) {
        if (x[i] == x[i + 1]) continue; // 同じ値は無視
        dist_pairs.pb(x[i + 1] - x[i]);
    }
    sort(all(dist_pairs), greater<ll>()); // 大きい順にソート
    ans = x_max - x_min;
    rep(i,m-1) {
        if (i < dist_pairs.size()) {
            ans -= dist_pairs[i];
        } else {
            break; // m-1個の距離を引いたら終了
        }
    }
    cout << ans << endl;

    return 0;
}
