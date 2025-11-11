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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> s(n+1);
    rep(i,n) cin >> a[i];
    rep(i,n) s[i+1] = (s[i] + a[i])%m;

    ll L = s[n];
    vector<ll> cnt(m);

    ll ans = 0;
    rep(r,n) {
        ans += cnt[s[r]];
        ans += cnt[(s[r] - L + m) % m];
        cnt[s[r]]++;
    }

    cout << ans << endl;

    return 0;
}
