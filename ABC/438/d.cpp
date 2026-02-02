#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n), sa(n), sb(n), sc(n);

    rep(i,n) {
        cin>>a[i];
        sa[i] = a[i];
        if (i > 0) sa[i] += sa[i-1];
    }
    rep(i,n) {
        cin>>b[i];
        sb[i] = b[i];
        if (i > 0) sb[i] += sb[i-1];
    }
    rep(i,n) {
        cin>>c[i];
    }
    for (int i = n-1;i>= 0;i--) {
        sc[i] = c[i];
        if (i != n-1) sc[i] += sc[i+1];
    }


    vector<ll> dp(n, LLONG_MIN);

    dp[1] = sa[0] + b[1];

    ll ans = LLONG_MIN;

    for(int i=1;i<n-1;i++){
        if(i > 1){
            dp[i] = max(
                dp[i-1] + b[i],
                sa[i-1] + b[i]
            );
        }
        chmax(ans, dp[i] + sc[i+1]);
    }

    cout << ans << endl;

    return 0;
}
