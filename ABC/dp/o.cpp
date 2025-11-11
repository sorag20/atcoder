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
 // bitdp
int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<mint> dp(1<<n, 0);
    dp[0] = 1;
    for (int i = 1; i < (1<<n); i++) {
        int x = __builtin_popcount(i);
        for (int j = 0; j < n; j++) {
            if (!(i & (1<<j))) continue;
            if (a[x-1][j] == 0) continue;
            dp[i]+= dp[i^(1<<j)];
        }
    }
    cout << dp[(1<<n)-1].val() << endl;
    return 0;
}
