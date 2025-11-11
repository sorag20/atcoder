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

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    map<ll, ll> cnt;
    rep(i, n) {
        cnt[a[i]]++;
    }
    vector<ll> c;
    for (auto &p : cnt) {
        c.pb(p.second);
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));
    dp[0][0] = 1; // Base case: one way to have zero elements with zero pairs
    int size = c.size();
    rep (i, size) {
        ll cv = c[i];
        rep (j,4) {
            dp[i+1][j] = dp[i][j];
            if (j) {
                dp[i+1][j] += dp[i][j-1] * cv;
            }
        }
    }
    cout << dp[size][3] << endl;

    return 0;
}
