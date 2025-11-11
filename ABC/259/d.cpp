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

struct V {
    ll x,y;
    V(ll x=0, ll y=0) : x(x), y(y) {}
};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    V s,t;
    cin >> s.x >> s.y;
    cin >> t.x >> t.y;
    vector<V> o(n);
    vector<ll> r(n);
    rep(i,n) {
        cin >> o[i].x >> o[i].y;
        cin >> r[i];
    }
    auto pow2 = [](ll x) { return x * x; };
    auto dist = [&](V a, V b) { return pow2(a.x - b.x) + pow2(a.y - b.y); };

    int si = 0;
    int ti = 0;
    rep(i,n) {
        if (dist(s,o[i]) == pow2(r[i])) si = i;
        if (dist(t,o[i]) == pow2(r[i])) ti = i;
    }
    dsu f(n);
    rep(i,n)rep(j,i) {
        ll d2 = dist(o[i],o[j]);
        ll r1 = r[i];
        ll r2 = r[j];
        if (d2 > pow2(r1 + r2)) continue;
        if (d2 < pow2(r2 - r1)) continue;
        f.merge(i,j);
    }
    if (f.same(si,ti)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}
