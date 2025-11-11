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
    ll n, k, p;
    cin >> n >> k >> p;
    map<vector<ll>, ll> dp;
    dp[vector<ll>(k)] = 0;

    rep(i, n)
    {
        ll c;
        cin >> c;
        vector<ll> a(k);
        rep(j,k) {
            cin >> a[j];
        }
        auto old = dp;
        for (auto[_d, v]: old) {
            vector<ll> d = _d;
            rep(j,k) {
                d[j] = min(d[j]+a[j], p);
            }
            if (dp.count(d)) dp[d] = min(dp[d], v + c);
            else dp[d] = v + c;
        }
    }    
    vector<ll> t(k, p);
    if (dp.count(t)) cout << dp[t] << endl;
    else cout << -1 << endl;
    return 0;
}
