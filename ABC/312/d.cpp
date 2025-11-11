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
using mint = modint998244353;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<mint>> dp(n+1, vector<mint>(n+1));
    dp[0][0] = 1;
    rep(i,n) {
        rep(j,n) {
            if (s[i] != ')') dp[i+1][j+1] += dp[i][j];
            if (s[i] != '(' && j >= 1) dp[i+1][j-1] += dp[i][j];
        }
    }
    cout << dp[n][0].val() << endl;
    return 0;
}
