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
    ll ans = 0;
    map<ll, ll> mp;
    rep(i,n) {
        ll s, c;
        cin >> s >> c;
        mp[s] = c;
    }

    while(mp.size()) {
        auto it = mp.begin();
        ll s = it->first;
        ll c = it->second;
        ans += c%2;
        mp.erase(it);
        s*=2; c /=2;
        if (c) mp[s] += c;
    }

    cout << ans << endl;
    return 0;
}
