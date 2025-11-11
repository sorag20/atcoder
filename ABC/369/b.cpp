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
    vector<vector<ll>> a(n+1, vector<ll>(n+1));
    rep(i,n) {
        rep(j,i+1) {
            cin >> a[i+1][j+1];
        } 
    }
    ll ans = 1;
    rep(i, n)
    {
        if (ans > i) {
            ans = a[ans][i+1];
        } else {
            ans = a[i+1][ans];
        }
    }
    cout << ans << endl;

    return 0;
}
