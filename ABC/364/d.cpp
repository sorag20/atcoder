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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    sort(all(a));

    rep(i,q) {
        ll b, k;
        cin >> b >> k;
        auto f = [&](ll x) -> bool {
            ll li = lower_bound(all(a), b-x) - a.begin();
            ll ri = lower_bound(all(a), b+x+1) - a.begin();
            return ri - li >= k;
        };
        ll ng = -1, ok = 2e9;

        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (f(mid)) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }
    
    return 0;
}
