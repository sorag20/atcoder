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
    vector<ll> c(n);
    rep(i,n){
        cin >> c[i];
    }
    vector<vector<ll>> a(n);
    rep(i,m){
        ll k;
        cin >> k;
        rep(j,k){
            ll x;
            cin >> x;
            x--;
            a[x].pb(i);
        }
    }
    ll ans = 1e18;
    // 全てのnに0,1,2回行くかを全通り試す
    rep(i, 1 << n) {
        rep(j, 1 << n) {
            vector<ll> cnt(n, 0);
            rep(k, n) {
                if (i & (1 << k)) {
                    cnt[k]++;
                }
                if (j & (1 << k)) {
                    cnt[k]++;
                }
            }
            vector<ll> check(m, 0);
            ll temp = 0;
            rep (k, n) {
                if (cnt[k] > 0) {
                    for (auto x : a[k]) {
                        check[x]+= cnt[k];
                    }
                    temp += c[k] * cnt[k];
                }
            }
            bool flag = true;
            rep(k, m) {
                if (check[k] <2) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = min(ans, temp);
            }
        }
    }
    cout << ans << endl;

   
  
    return 0;
}
