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
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for(int i=0;i<x;i++)
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const ll INF = 1e18;
struct P {
    ll r, c;
};

// ax + b = cx +dのxを解く関数
ll calc(ll a, ll b, ll c, ll d) {
    if (a == c) return (b == d) ? INF : -1;
    a -= c;
    d -= b;
    if (a < 0) a = -a, d = -d;
    if (d%a != 0) return -1;
    return d/a;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    P t, a;
    cin>> t.r>> t.c >> a.r >> a.c;
    ll n;
    int m, l;
    cin>> n >> m >> l;
    vector<pair<char, ll>> pt, pa;
    rep(_,2) {
        ll now = 0;
        rep(i,m) {
            char s; ll a;
            cin>> s>>a;
            now += a;
            pt.emplace_back(s,now);
        }
        swap(pt, pa);
        swap(m,l);
    }
    map<char, P> mp;
    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};
    mp['L'] = {0, -1};
    mp['R'] = {0, 1};

    int ti = 0, ai = 0;
    ll now = 0;
    ll ans = 0;
    while(ti < m && ai < l) {
        ll nxt = min(pt[ti].second, pa[ai].second);

        ll w = nxt - now;
        P dt = mp[pt[ti].first];
        P da = mp[pa[ai].first];
        {
            ll rx = calc(dt.r, t.r, da.r, a.r);
            ll cx = calc(dt.c, t.c, da.c, a.c);

            if (rx != -1 && cx != -1) {
                if (rx == INF) swap(rx, cx);
                if (rx == INF) {
                    ans += w;
                } else if (cx == INF) {
                    if (0 < rx && rx <= w) ans+= 1;
                } else {
                    if (rx == cx && 0 < rx && rx <= w) ans += 1;
                }
            }
        }

        t.r += dt.r * w; t.c +=dt.c* w;
        a.r += da.r* w; a.c +=da.c* w;
        if (nxt == pt[ti].second) ti++;
        if (nxt == pa[ai].second) ai++;
        now = nxt;
    }
    cout << ans <<endl;

    return 0;
}
