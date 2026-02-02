#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using l3 = __int128;

l3 asum(l3 a, l3 d, l3 n) {
    return (a + (a+d*(n-1))) * n/2;
}

ll f(ll l, ll r, ll d, ll h) {
    if (l+1 == r) return l;
    ll c = (l + r) / 2;
    l3 s = asum(l*d, d, c-l);
    if (s < h) return f(c, r, d,h-s);
    else return f(l,c,d,h);
}

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, h;
    cin >> n >> h;
    vector<P> a;
    rep(i,n) {
        int t, d;
        cin>> t>> d;
        a.eb(t,d);
    }
    sort(all(a));

    ll max_td = 0;
    multiset<int> ds;
    rep(i,n) ds.insert(a[i].second);
    ds.insert(0);

    auto solve = [&](ll l, ll r) {
        ll max_d = *ds.rbegin();
        ll ac = l -1, wa = r;
        while(ac+1 < wa) {
            ll wj = (ac + wa)/2;
            if (max_td < max_d*wj) wa = wj;
            else ac = wj;
        }
        {
            l3 tot = l3(wa - l)*max_td;
            if (tot<h) {
                h -= tot;
            } else {
                ll ans = l+((h-1)/max_td);
                cout << ans << endl;
                return true;
            }
        }
        {
            ll tot = asum(wa , 1 , r-wa)*max_d;
            if (tot<h) h-=tot;
            else{
                ll ans = f(wa,r, max_d, h);
                cout << ans << endl;
                return true;
            }
        }
        return false;
    };
    ll l = 1;
    rep(i,n) {
        ll r;
        auto [t,d] = a[i];
        r = t;
        if (solve(l,r)) return 0;
        ds.erase(ds.find(d));
        chmax(max_td, (ll)t*d);
        l = r;
    }
    solve(l, l+h+1);

    return 0;
}
