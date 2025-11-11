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
    cin >> n>>m;
    vector<ll> a(n);
    vector<ll> b(m);
    map<ll,ll> map;
    rep(i, n) {
        cin >> a[i];
        map[a[i]]++;

    }
    rep(i, m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    ll ans = 0;
    rep(i, m)
    {

        auto index = map.lower_bound(b[i]);
        if (index == map.end()) {
            cout << -1 << endl;
            return 0;
        }
        ll value = index->first;
        ans += value;
        if (index->second == 1)
        {
            map.erase(value);
        } else {
            map[value]--;
        }
    }
    cout << ans << endl;

    return 0;
}

