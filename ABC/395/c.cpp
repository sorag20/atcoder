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
    vector <ll> a(n);
    rep(i,n) cin >> a[i];
    map<ll, set<ll>> mp;
    rep(i,n) {
        mp[a[i]].insert(i);
    }

    ll ans = 10000001;
    rep(i,n) {
        if (mp[a[i]].size() != 0 && mp[a[i]].size() != 1) {
            // mp[s[i]]の最大値と最小値を取得
            auto it = mp[a[i]].begin();
            ll min = *it;
            it++;
            ll max = *it;
            if (max - min +1 < ans) ans = max - min +1;
        }
    }

    if (ans == 10000001) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}
