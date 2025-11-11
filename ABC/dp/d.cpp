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
#define rep(i, x) for (int i = 0; i < x; i++)
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
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, 0));
    rep(i, n)rep(j, w + 1) {
        if (j + weight[i] <= w) {
            dp[i + 1][j + weight[i]] = max(dp[i + 1][j + weight[i]], dp[i][j] + value[i]);
        }
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    }
    cout << dp[n][w] << endl;

    return 0;
}
