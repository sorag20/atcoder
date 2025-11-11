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
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum <= m) {
        cout << "infinite" << endl;
        return 0;
    }
    sort(all(a));
    ll max_a = a[n-1];
    // 1からmax_aまでの数を二分探索
    ll l = 0, r = 2*max_a;
    while (r-l > 1) {
        ll x = (l+r)/2;
        ll cnt = 0;
        rep(i,n) {
            cnt += min(x, a[i]);
        }
        if (cnt > m) {
            r = x;
        } else {
            l = x;
        }
    }
    cout<< l << endl;


    return 0;
}
