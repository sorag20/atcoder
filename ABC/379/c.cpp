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
    vector<lP> a(m);
    rep(i, m) cin >> a[i].first;
    rep(i, m) cin >> a[i].second;
    sort(all(a));
    a.emplace_back(n+1, 1);

    ll ans = 0;
    int px = 0;
    ll num  = 1;
    for (auto [x, i] : a) {
        ll L = x - px;
        ll carry = num - L;
        ans += (L-1)*L/2;
        ans += L*carry;
        if (carry < 0) {
            cout << -1 << endl;
            return 0;
        }

        px = x;
        num = carry + i;
    }
    if (num != 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
