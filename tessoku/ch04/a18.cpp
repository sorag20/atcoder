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

    ll n,s;
    cin >> n>>s;
    vector<ll> a(n+1);
    ll const M = 10005;
    vector<vector<bool>> dp(n+1, vector<bool> (M));
    rep(i,n) cin>>a[i+1];
    dp[0][0] = true;
    for (int i = 1;i <= n;i++) {
        rep(j,M) {
            if (dp[i-1][j]) dp[i][j] = dp[i-1][j];
            if (j + a[i] < M) {
                dp[i][j+a[i]] = dp[i-1][j];
            }
        }
    }
    if (dp[n][s]) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
