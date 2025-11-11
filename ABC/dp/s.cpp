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
using mint = modint1000000007;
// 桁DP
int main()
{
    string k;
    int d;
    cin >> k >> d;
    int n = k.size();
    vector<vector<vector<mint>>> dp(n+1, vector<vector<mint>>(d+1, vector<mint>(2, 0)));
    dp[0][0][0] = 1;
    rep(i, n) {
        int x = k[i] - '0';
        rep(j, d)rep(isless, 2) {
            for (int y = 0; y < 10; y++) {
                if (y < x) {
                    dp[i+1][(j+y)%d][1] += dp[i][j][isless];
                } else if (y == x) {
                    dp[i+1][(j+y)%d][isless] += dp[i][j][isless];
                } else {
                    if (isless) {
                        dp[i+1][(j+y)%d][isless] += dp[i][j][isless];
                    }
                }
            }
        }
     }

     mint ans = dp[n][0][0] + dp[n][0][1] - mint(1);
     cout << ans.val() << endl;
    return 0;
}
