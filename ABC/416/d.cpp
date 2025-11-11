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

    ll t;
    cin >> t;
    while(t--) {
        ll n,m;
        cin >> n >> m;
        vector<ll> a(n), b(n);
        rep(i, n) {
            cin >> a[i];
        }
        rep(i, n) {
            cin >> b[i];
        }
        ll ans = 0;
        rep(i,n) {
            ans += a[i] + b[i];
        }
        sort(gall(a));
        sort(all(b));

        int bi = 0;
        rep(i,n) {
            while(bi < n && a[i] + b[bi] < m) bi++;
            if (bi == n) break;
            ans -= m;
            bi++;
        }

        cout << ans << endl;
    }
    return 0;
}
