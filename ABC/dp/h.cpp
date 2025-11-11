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
using mint =modint1000000007;

int main()
{
    ll n, w;
    cin >> n >> w;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<vector<mint>> dp(n+1, vector<mint>(w+1, 0));
    dp[0][0] = 1;
    rep(i,n)rep(j,w) {
        if (i + 1 <n && s[i+1][j] == '.') {
            dp[i+1][j] += dp[i][j];
        }
        if (j < w && s[i][j+1] == '.') {
            dp[i][j+1] += dp[i][j];
        }
    }
    cout << dp[n-1][w-1].val() << endl;
    
    return 0;
}
