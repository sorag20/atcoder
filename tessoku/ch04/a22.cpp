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
    vector<ll> a(n), b(n);
    for (int i = 1;i < n ;i++) cin>>a[i];
    for (int i = 1;i < n ;i++) cin>>b[i];
    vector<ll> dp(n+1);
    for (int i = 1;i < n ;i++) {
        if (a[i] <= n ) chmax(dp[a[i]], dp[i] + 100);
        if (b[i] <= n ) chmax(dp[b[i]], dp[i] + 150);
    }
    cout << dp[n] << endl;
    return 0;
}
