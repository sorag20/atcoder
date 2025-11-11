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
    vector<ll> a(n), s(n+1);
    rep(i, n) cin >> a[i];
    s[0] = a[0];
    for (int i = 1; i < n; i++) {
        s[i] = s[i-1] + a[i];
    }
    const ll INF = 1e18;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));

    auto solve = [&](auto solve, int l, int r) -> ll {
        if (l == r) return 0;
        if (dp[l][r] != INF) return dp[l][r];
        for (int i = l; i < r; i++) {
            ll s_sum = 0;
            if (l == 0) s_sum = s[r];
            else s_sum = s[r] - s[l-1];
            dp[l][r] = min(dp[l][r], solve(solve, l, i) + solve(solve, i + 1, r) + s_sum);
        }
        return dp[l][r];
    };
    cout << solve(solve, 0, n-1) << endl;

    return 0;
}
