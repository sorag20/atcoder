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
    vector<lP> data;
    ll w = 0;
    rep(i,n) {
        ll x, y, z;
        cin >> x >> y >> z;
        // 何人鞍替えをすれば良いか
        ll a = max((ll)0, (y-x+1)/2);
        w += z;
        data.emplace_back(a, z*2);
    }
    ll INF = 1e18;
    vector<vector<ll>> dp(n+1, vector<ll>(2*w+1, INF));
    dp[0][0] = 0;
    rep(i,n) {
        rep(j, w+1) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if (j+data[i].second <= 2*w) {
                dp[i+1][j+data[i].second] = min(dp[i+1][j+data[i].second], dp[i][j]+data[i].first);
            }
        }
    }
    ll ans = INF;
    for (ll i = w; i <= 2*w; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans<< endl;
    return 0;
}
