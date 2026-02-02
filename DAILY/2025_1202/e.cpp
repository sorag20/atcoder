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
using mint = modint998244353;

mint dp[1000005][9];

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    rep(i,9) {
        dp[0][i] = 1;
    }

    for(int i = 1;i < n;i++) {
        rep(j,9) {
            dp[i][j] += dp[i-1][j];
            if (j-1 >= 0) dp[i][j] += dp[i-1][j-1];
            if (j+1 < 9) dp[i][j] += dp[i-1][j+1];
        }
    }
    mint ans = 0;
    rep(i,9) {
        ans += dp[n-1][i];
    }
    cout << ans.val() << endl;

    return 0;
}
