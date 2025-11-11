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

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));

    auto solve = [&](auto solve, int l, int r) -> ll {
        if (dp[l][r] != 0) return dp[l][r];
        if (l == r) return 0;
        return dp[l][r] = max(a[l] - solve(solve, l + 1, r), a[r-1] - solve(solve, l, r - 1));
    };

    cout << solve(solve, 0, n) << endl;
    return 0;
}
