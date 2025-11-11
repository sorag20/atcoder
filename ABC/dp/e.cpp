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
    ll n, w;
    cin >> n >> w;
    vector<ll> weight(n), value(n);
    rep(i, n) cin >> weight[i] >> value[i];
    const ll INF = 1e18;
    const ll MAX = 1e5;
    vector<vector<ll>> dp(n+1, vector<ll>(MAX+1, INF));
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, MAX) {
            if (j + value[i] <= MAX) {
                dp[i + 1][j + value[i]] = min(dp[i + 1][j + value[i]], dp[i][j] + weight[i]);
            }
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= MAX; i++) {
        if (dp[n][i] <= w) {
            ans = max(ans, i);
        }
    }
    cout << ans << endl;

    return 0;
}
