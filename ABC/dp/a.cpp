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
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    const ll INF = 1e18;
    vector<ll> dp(n, INF);
    dp[0] = 0;
    rep(i,n-1) {
        dp[i+1] = min(dp[i+1], dp[i] + abs(h[i+1] - h[i]));
        if (i < n-2) {
            dp[i+2] = min(dp[i+2], dp[i] + abs(h[i+2] - h[i]));
        }
    }
    cout << dp[n-1]<<endl;
    return 0;
}
