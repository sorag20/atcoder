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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<lP> pa(n+2);
    rep(i,n) {
        ll p, a;
        cin >> p >> a;
        pa[i+1].first = p;
        pa[i+1].second = a;
    }
    vector<vector<ll>> dp(n+2, vector<ll> (n+2, 0));

    for (int len = n-1; len >= 0; len--) {
        for (int l = 1;l <= n;l++) {
            int r = l + len;
            if (r > n) continue;
            // 左端のブロックlを取る場合
            ll score1 = 0;
            if (l <= pa[l-1].first && pa[l-1].first <= r) {
                score1 = pa[l-1].second;
            }

            ll score2 = 0;
            if (l <= pa[r+1].first && pa[r+1].first <= r) {
                score2 = pa[r+1].second;
            }
            dp[l][r] = max(dp[l-1][r] + score1, dp[l][r+1] + score2);
        }
    }

    ll ans = 0;
    rep(i,n) {
        chmax(ans, dp[i+1][i+1]);
    }

    cout << ans << endl;


    return 0;
}
