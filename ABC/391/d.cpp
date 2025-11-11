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
    ll n, w;
    cin >> n >> w;
    vector<ll> x(n), y(n);
    rep(i,n) {
        cin >> x[i] >> y[i];
        x[i]--;
    }
    vector<ll> idx(n);
    rep(i,n) idx[i] = i;
    sort(all(idx), [&](ll a, ll b) { return y[a] < y[b]; });
    // rは、i番目のブロックがその列で何番目か
    vector<ll> r(n), num(w);
    for (int i : idx) {
        r[i] = num[x[i]];
        num[x[i]]++;
    }

    const ll INF = 1e18;
    // 格段が何秒後に消えるか
    vector<ll> d(n, INF);


    vector<vector<ll>> blocks(n);
    rep(i,n) blocks[r[i]].pb(i);
    rep(i,n) {
        if (blocks[i].size() != w) continue;
        ll max_y = 0;
        for (int j : blocks[i]) {
            max_y = max(max_y, y[j]);
        }
        d[i] = max_y;
    }
    ll q;
    cin >> q;
    while (q--) {
        ll t, a;
        cin >> t >> a;
        a--;
        if (d[r[a]] <= t) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}
