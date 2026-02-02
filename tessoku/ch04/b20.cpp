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
// 編集距離
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;

    ll const INF = 1e18;
    vector<vector<ll>> dp(2005, vector<ll> (2005, INF));

    dp[0][0] = 0;
    rep(i,s.size()+1) dp[i][0] = i;
    rep(j,t.size()+1) dp[0][j] = j;

    for (int i = 1; i<= s.size();i++) {
        for (int j = 1;j <= t.size();j++) {
            if (s[i-1] == t[j-1]) chmin(dp[i][j], dp[i-1][j-1]);
            chmin(dp[i][j], dp[i-1][j] + 1);
            chmin(dp[i][j], dp[i][j-1] + 1);
            chmin(dp[i][j], dp[i-1][j-1] + 1);
        }
    }

    cout << dp[s.size()][t.size()] << endl;



    return 0;
}
