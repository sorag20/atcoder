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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n+1);
    rep(i,m) {
        ll l, r;
        cin >> l >> r;
        a[l]++;
        if (r + 1 <= n) {
            a[r + 1]--;
        }
    }
    rep(i,n) {
        a[i + 1] += a[i];
    }
    ll ans = 1e6;
    for (int i = 1; i <= n; i++) 
    {
        ans = min(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}
