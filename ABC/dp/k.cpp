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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<bool> dp(k + 1, false);
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            if (j - a[i] >= 0 && !dp[j - a[i]]) {
                dp[j] = true;
            }
        }
    }
    if (dp[k]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    
    return 0;
}
