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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n, h, m;
    cin >> n >> h >> m;
    vector<vector<ll>> dp(n + 1, vector<ll>(h + 1, -1));
    dp[0][h] = m;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        rep(j, h + 1) {
            if (dp[i][j] == -1) continue;
            if (a <= j) {
                chmax(dp[i + 1][j - a], dp[i][j]);
            }
            if (b <= dp[i][j]) {
                chmax(dp[i + 1][j], dp[i][j] - b);
            }
        }
        if (dp[i+1] == vector<ll>(h + 1, -1)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;

    return 0;
}
