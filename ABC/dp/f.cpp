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
//lcs
int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    rep(i,n)rep(j,m) {
        if (s[i] == t[j]) {
            dp[i+1][j+1] = dp[i][j] + 1;
        } else {
            dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    int len = dp[n][m];
    string ans = "";
    n--;m--;
    int i = n, j = m;

    while(len) {
        if (s[i] == t[j]) {
            ans += s[i];
            i--;
            j--;
            len--;
        } else {
            if (dp[i+1][j] == dp[i][j]) {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(all(ans));
    cout << ans << endl;

    return 0;
}
