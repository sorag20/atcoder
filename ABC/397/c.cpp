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
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    set<ll> left, right;
    map<ll, ll> mp_left, mp_right;
    int ans = 0;
    rep(i,n) {
        if (i == 0) {
            left.insert(a[i]);
            mp_left[a[i]]++;
        } else {
            mp_right[a[i]]++;
            right.insert(a[i]);
        }
    }
    ans = max(ans, (int)left.size() + (int)right.size());

    for (int i = 1; i < n; i++) {
        ll x = a[i];
        left.insert(a[i]);
        mp_left[a[i]]++;
        mp_right[a[i]]--;
        if (mp_right[a[i]] == 0) {
            right.erase(a[i]);
        }
        ans = max(ans, (int)left.size() + (int)right.size());
    }
    
    cout << ans << endl;
    return 0;
}
