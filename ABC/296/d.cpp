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
    ll ans = 2e18;
    for (ll i = 1; i*i -i <= m+1; i++) {
        ll j = (m+i-1)/i;
        if (i*j >= m && i <= n && j <= n) {
            ans = min(ans, i*j);
        }
    }

    if (ans == 2e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}
