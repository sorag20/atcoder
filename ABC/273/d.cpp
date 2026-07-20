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
    unordered_map<ll, set<ll>> xy, yx;
    unordered_map<ll, set<ll, std::greater<ll>>> xy_g, yx_g;
    rep(i,n) {
        ll r,c; cin>>r>>c;
        r--;c--;
        xy[r].insert(c);
        yx[c].insert(r);
        xy_g[r].insert(c);
        yx_g[c].insert(r);
    }

    ll q;
    cin >> q;
    while (q--) {
        char c;
        ll l;
        cin >> c >> l;
        if (c == 'D') {
            auto it = yx[t].lower_bound(s);
            if (it != yx[t].end()) {
                s = min(*it-1, s+l);
            } else {
                s = min(s+l,h-1);
            }
        } else if (c == 'U') {
            auto it = yx_g[t].lower_bound(s);
            if (it != yx_g[t].end()) {
                s = max(*it+1, s-l);
            } else {
                s = max(s-l,0LL);
            }
        } else if (c == 'L') {
            auto it = xy_g[s].lower_bound(t);
            if (it != xy_g[s].end()) {
                t = max(t-l, *it+1);
            } else {
                t = max(0LL,t-l);
            }
        } else if (c == 'R') {
            auto it = xy[s].lower_bound(t);
            if (it != xy[s].end()) {
                t = min(*it-1, t+l);
            } else {
                t = min(t+l, w-1);
            }
        }
        cout << s + 1 << " " << t + 1 << endl;
    }

    return 0;
}
