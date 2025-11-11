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
    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
    rep(i,n) {
        ll a, b, c;
        cin >> a >> b >> c;
        dp[i+1][0] = max(dp[i][1] + a, dp[i][2] + a);
        dp[i+1][1] = max(dp[i][0] + b, dp[i][2] + b);
        dp[i+1][2] = max(dp[i][0] + c, dp[i][1] + c);
    }
    ll ans = 0;
    rep(i,3) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
