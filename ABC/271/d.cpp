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

    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector dp(n + 1, vector<bool>(s + 1, false));
    dp[0][0] = true;
    rep(i, n)
    {
        rep(j, s + 1)
        {
            if (dp[i][j]) {
                if (j + a[i] <= s) dp[i + 1][j + a[i]] = true;
                if (j + b[i] <= s) dp[i + 1][j + b[i]] = true;
            }
        }
    }
    if (!dp[n][s])
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    string ans = "";
    for (int i = n - 1; i >= 0; i--)
    {
        if (s - a[i] >= 0 && dp[i][s - a[i]])
        {
            ans += "H";
            s -= a[i];
        }
        else
        {
            ans += "T";
            s -= b[i];
        }
    }
    reverse(all(ans));
    cout << ans << endl;


    return 0;
}
