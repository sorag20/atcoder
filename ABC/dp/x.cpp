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
    vector<ll> w(n), s(n), v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> s[i] >> v[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(100001, 0));
    vector<ll> sort_array(n);
    rep(i, n)
    {
        sort_array[i] = i;
    }
    sort(sort_array.begin(), sort_array.end(), [&](ll a, ll b)
         { return min(s[a], s[b] - w[a]) > min(s[b], s[a] - w[b]);});

    rep(i,n) {
        rep(j, 100001) {
            int a = sort_array[i];
            dp[i + 1][j] = max(dp[i+1][j], dp[i][j]);
            if (j <= s[a]) {
                dp[i+1][j+w[a]] = max(dp[i][j+w[a]], dp[i][j] + v[a]);
            }
        }
    }
    ll ans = 0;
    rep(j, 100001) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << endl;
    return 0;
}
