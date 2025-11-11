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
    ll n,k;
    cin >> n>>k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    sort(all(a));
    ll x = 0, y = n - 1;
    ll mid = 0;
    if (n % 2 == 1) {
        mid = a[n / 2];
    } else {
        mid = (a[n / 2] + a[n / 2 - 1]) / 2;
    }
    rep(i, k)
    {
        if (mid -a[x]> a[y]-mid) {
            x++;
        } else {
            y--;
        }
        if (n % 2 == 1) {
            mid = a[n / 2];
        } else {
            mid = (a[n / 2] + a[n / 2 - 1]) / 2;
        }
    }
    cout << a[y]-a[x] << endl;

    return 0;
}
