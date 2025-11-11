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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    const ll max_val = 3001;
    vector<mint> dp(max_val, 0);
    dp[0] = 1; 
    rep(i,n) {
        vector<mint> new_dp(max_val, 0), dp_sum(max_val, 0);
        rep(j, max_val) {
            dp_sum[j] += dp[j];
            if (j > 0) dp_sum[j] += dp_sum[j - 1];
        }
        rep(j, max_val) {
            if (j >= a[i] && j <= b[i]) {
                new_dp[j] = dp_sum[j];
            }
        }
        dp = new_dp;
    }

    mint ans = 0;
    rep(i, max_val) {
        ans += dp[i]
    }
    cout << ans.val() << endl;

    return 0;
}
