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
    rep(i,t) {
        ll n;
        cin >> n;
        vector<ll> a(n), cnt(30);
        rep(j, n) {
            cin >> a[j];
        }
        rep(j,n) {
            rep(k, 30) {
                if (a[j] & (1 << k)) {
                    cnt[k]++;
                }
            }
        }
        ll ans = 0;
        rep(j, n) {
            ll tmp = 0;
            rep(k, 30) {
                if (a[j] & (1 << k)) {
                    tmp += (1 << k) * (n - cnt[k]);
                } else {
                    tmp += (1 << k) * cnt[k];
                }
            }
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }

    return 0;
}
