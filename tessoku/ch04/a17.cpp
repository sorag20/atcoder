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
    vector<ll> a(n),b(n),dp(n, INF), ans;
    for (int i = 1;i< n;i++) cin >> a[i];
    for (int i = 2;i< n;i++) cin >> b[i];
    dp[0] = 0;
    rep(i,n) {
        if (i >= 1) chmin(dp[i], dp[i-1] + a[i]);
        if (i >= 2) chmin(dp[i], dp[i-2] + b[i]);
    }
    ans.pb(n-1);
    for (int i = n-1;i >= 1;i--) {
        if (dp[i] == dp[i-1] + a[i]) {
            ans.pb(i-1);
        } else {
            ans.pb(i-2);
            i--;
        }
    }
    cout << ans.size() << endl;
    reverse(all(ans));
    for (auto a: ans) {
        cout << a+1 << ' ';
    }
    cout << endl;

    return 0;
}
