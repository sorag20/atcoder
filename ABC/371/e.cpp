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
ll cm2 (ll c) {
    return c * (c-1) / 2;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<ll>> is(n);
    rep(i,n){
        is[a[i]].pb(i);
    }

    ll ans = 0;
    rep(x, n) {
        ll sx = 0;
        is[x].pb(n);
        int pre = -1;
        for (int i : is[x]) {
            sx += cm2(i - pre-1) + i - pre-1;
            pre = i;
        }
        ans += cm2(n)+n - sx;
    }
    cout << ans << endl;
    return 0;
}
