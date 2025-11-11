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
using mint  = modint1000000007;

// 挿入DP
int main()
{
    ll n;
    string s;
    cin >> n >> s;
    vector<vector<mint>> dp(n+1, vector<mint>(n+1, 0));
    dp[1][1] = 1;
    for (int i = 1; i < n; i++) {
            if (s[i - 1] == '<') {
                mint sum = 0;
                for (int j = 1; j <= i; j++) {
                    sum += dp[i][j];
                    dp[i+1][j+ 1] += sum;
                }
            } else {
                mint sum = 0;
                for (int j = i; j >= 1; j--) {
                    sum += dp[i][j];
                    dp[i+1][j] += sum;
                }
            }
    }
    mint ans = 0;
    rep(i, n+1) {
        ans += dp[n][i];
    }
    cout << ans.val() << endl;


    return 0;
}
