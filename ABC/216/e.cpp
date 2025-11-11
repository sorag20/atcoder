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

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll wa = -1; ll ok = 2e10;

    auto check = [&](ll x) {
        ll sum = 0;
        rep(i, n) sum += max(0LL, a[i] - x);
        return sum;
    };

    while (ok - wa > 1) {
        ll mid = (wa + ok) / 2;
        if (check(mid) < k) ok = mid;
        else wa = mid;
    }

    ll ans = 0;
    auto getAsum = [&](ll l, ll r) {
        return ((l + r)* (r - l + 1)) / 2;
    };

    rep(i,n) {
        if (a[i] >= ok) {
            ans += getAsum(ok + 1, a[i]);
        }
    }
    ans += ok * (k - check(ok));
    cout << ans << endl;

    return 0;
}
