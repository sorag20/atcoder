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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    set<ll> s;
    s.insert(0);
    rep(i, k) {
        ll min_s = *s.begin();
        s.erase(s.begin());
        for (ll j = 0; j < n; j++) {
            s.insert(min_s + a[j]);
        }
    }
    cout << *s.begin() << endl;

    return 0;
}
