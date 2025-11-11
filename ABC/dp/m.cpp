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

int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<vector<mint>> dp(n+1, vector<mint> (k+1, 0));
    dp[0][0] = 1;
    rep(i,n) {
        vector<mint> sum_dp(k+2, 0);
        rep(j,k+1) {
            sum_dp[j+1] = sum_dp[j] + dp[i][j];
        }
        rep(j,k+1) {
            dp[i+1][j] = sum_dp[j+1] - sum_dp[max(0LL, j - a[i])];
        }
    }
    
    cout << dp[n][k].val() << endl;
    return 0;
}
