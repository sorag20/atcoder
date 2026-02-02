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
    ll const INF = 1e18;
    vector<ll> h(n), dp(n,INF);
    rep(i,n) cin>>h[i];
    dp[0] = 0;
    rep(i,n) {
        if (i < n-1) chmin(dp[i+1], dp[i] + abs(h[i+1] - h[i]));
        if (i < n-2) chmin(dp[i+2], dp[i] + abs(h[i+2] - h[i]));
    }
    cout << dp[n-1] << endl;

    return 0;
}
