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

    vector<lP> g;
    rep(i, m)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        g.emplace_back(a,b);
    }
    const ll INF = 1e18;
    ll ans = INF;
    rep(i, 1<<n) {
        ll cnt = 0;
        vector<ll> color(n);
        rep(j,n) {
            if (i>>j&1) color[j] = 1;
        }
        for (auto [s,t] : g) {
            if (color[s] == color[t]) cnt++;
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
