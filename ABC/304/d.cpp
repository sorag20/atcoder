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
    ll w, h, n;
    cin >> h >> w >> n;
    vector<lP> p;
    rep(i,n) {
        ll a, b;
        cin >> a >> b;
        p.pb({a, b});
    }
    ll A, B;
    cin >> A;
    vector<ll> a, b;
    rep(i, A) {
        ll x;
        cin >> x;
        a.pb(x);
    }
    cin>> B;
    rep(i, B) {
        ll x;
        cin >> x;
        b.pb(x);
    }
    ll ans_min = 1e18, ans_max = 0;
    map<lP, ll> mp;
    rep(i,n) {
        ll x, y;
        x = lower_bound(all(a), p[i].first) - a.begin();
        y = lower_bound(all(b), p[i].second) - b.begin();
        mp[{x, y}]++;
    }
    if (mp.size() < (A+1)*(B+1)) {
        ans_min = 0;
    }
    for (auto nv : mp) {
        ans_max = max(ans_max, nv.second);
        ans_min = min(ans_min, nv.second);
    }
    cout << ans_min << ' ' << ans_max << endl;
    return 0;
}
