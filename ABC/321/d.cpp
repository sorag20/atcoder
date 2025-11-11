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
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    vector<ll> s(n+1);
    rep(i,n) {
        cin >> a[i];
    }
    sort(all(a));
    rep(i,n) {
        s[i+1] = s[i] + a[i];
    }
    rep(i,m) {
        cin >> b[i];
    }
    ll ans = 0;
    rep(i,m) {
        auto it = lower_bound(all(a), p - b[i]);
        if (it == a.end()) {
            ans += b[i] * n + s[n]  ;
        } else {
            ll idx = it - a.begin();
            ans += b[i] * idx + s[idx];
            ans += p * (n - idx);
        }
    }
    cout << ans << endl;
    
    return 0;
}
