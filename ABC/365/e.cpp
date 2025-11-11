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

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> s(n+1);
    rep(i,n) cin >> a[i];
    rep(i,n) s[i+1] = s[i]^a[i];

    ll ans = 0;
    rep(k, 30) {
        ll cnt = 0;
        rep(i,n+1) {
            if (s[i]&1<<k) cnt++;
        }
         ans += cnt*(n+1-cnt) * (1<<k);

    }
    rep(i,n) ans -= a[i];
    cout << ans << endl;
    return 0;
}
