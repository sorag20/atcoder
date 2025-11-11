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
    vector<double> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<double>> dp(n+1, vector<double>(n+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i+1][j] += dp[i][j] * (1 - a[i]);
            dp[i+1][j+1] += dp[i][j] * a[i];
        }
    }
    double ans = 0;
    for(int i = n/2 + 1; i <= n; i++) {
        ans += dp[n][i];
    }
    printf("%.10f\n", ans);
    return 0;
}
