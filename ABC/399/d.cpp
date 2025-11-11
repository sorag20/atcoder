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
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n*2);
        rep(i, 2*n) {
            cin >> a[i];
        }
        vector<vector<ll>> index(n);
        set<lP> used;
        rep(i, 2*n) {
            ll A = a[i];
            A--;
            index[A].pb(i);
        }
        rep(i, 2*n-1) {
            int x = a[i];
            int y = a[i+1];
            if (x > y) {
                swap(x, y);
            }
            if (x == y) {
                continue;
            }
            x--;
            y--;
            used.insert({x, y});
        }
        ll ans = 0;
        for (auto p : used) {
            ll x = p.first;
            ll y = p.second;
            ll xl = index[x][0];
            ll xr = index[x][1];
            ll yl = index[y][0];
            ll yr = index[y][1];
            if (xr - xl == 1 || yr - yl == 1) {
                continue;
            }
            if (abs(xl - yl) == 1 && abs(xr - yr) == 1) {
                ans++;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
