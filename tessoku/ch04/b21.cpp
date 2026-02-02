#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for(int i=0;i<x;i++)
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

// 回文
// 区間DPは、1-indexにすると書きやすい
int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    string s;
    cin >> n >> s;
    vector<vector<ll>> dp(n+2, vector<ll> (n+2));
    rep(i,n) {
        dp[i+1][i+1] = 1;
    }

    for (int len = 1;len <= n;len++) {
         for (int l = 1;l <= n;l++) {
            int r = l + len;
            if (r > n) continue;
            if (s[l-1] == s[r-1]) {
                dp[l][r] = max(dp[l+1][r], max(dp[l][r-1], dp[l+1][r-1] + 2));
            } else {
                dp[l][r] = max(dp[l+1][r], max(dp[l][r-1], dp[l+1][r-1]));
            }
         }
    }
    cout << dp[1][n] << endl;

    return 0;
}
