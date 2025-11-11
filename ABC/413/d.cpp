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
        ll n;
        cin >> n;
        vector<ll> a(n);
        rep(i, n) {
            cin >> a[i];
        }
        sort(all(a), [](ll x, ll y) { return abs(x) < abs(y); });
        bool ok = true;
        if (abs(a[0]) == abs(a[n-1])) {
            ll minus_count = 0, plus_count = 0;
            rep(i, n) {
                if (a[i] < 0) {
                    minus_count++;
                } else {
                    plus_count++;
                }
            }
            if (abs(minus_count - plus_count) > 1) {
                ok = false;
            }
        } else ok = false;
        bool a_ok = 1;
        rep(i, n-2) {
            if (a[i] * a[i+2] != a[i+1] * a[i+1]) {
                a_ok = false;
            }
        }
        if (ok || a_ok) {
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }

    return 0;
}
