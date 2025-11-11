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

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i,n) {
        cin >> a[i];
    }
    rep(i,n) {
        cin >> b[i];
    }
    ll ans = 0;
    rep(i,n) {
        ans += min(a[i], b[i]);
    }
    rep(i,q) {
        char c;
        cin >> c;
        ll x, y;
        cin >> x >> y;
        if (c == 'A') {
            x--;
            ll min_ab = min(a[x], b[x]);
            a[x] = y;
            if (min_ab > min(a[x], b[x])) {
                ans += a[x] - min_ab;
            } else {
                ans += min(a[x], b[x]) - min_ab;
            }
        } else {
            x--;
            ll min_ab = min(a[x], b[x]);
            b[x] = y;
            if (min_ab > min(a[x], b[x])) {
                ans += b[x] - min_ab;
            } else {
                ans += min(a[x], b[x]) - min_ab;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
