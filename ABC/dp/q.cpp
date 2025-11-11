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
//LIS Longest Increasing Subsequence

ll op (ll a, ll b) { return max(a, b); }
ll e() { return 0; }

int main()
{
    ll n;
    cin >> n;
    vector<ll> h(n), a(n);
    rep(i, n) cin >> h[i];
    rep(i, n) cin >> a[i];

    segtree<ll, op, e> seg(n+1);

    for (int i = 0; i < n; i++) {
        ll m = seg.prod(0, h[i]);
        seg.set(h[i], m + a[i]);
    }
    cout << seg.all_prod() << endl;

    return 0;
}
