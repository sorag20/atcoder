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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,q;
    cin >> n >> q;
    vector<ll> A(n),s(n);
    rep(i,n) cin >> A[i];
    rep(i,n) {
        if (i == 0) s[i] = A[i];
        else s[i] = s[i-1] + A[i];
    }
    ll cnt = 0;
    rep(i,q) {
       ll t;
       cin >> t;
       if (t == 1) {
           ll c;
           cin >> c;
           cnt += c;
           cnt%=n;
       }else {
           ll l,r;
           cin >> l >> r;
           l--;r--;
           ll ans = 0;
           l += cnt;
           l%=n;
           r += cnt;
           r%=n;
           if (l <= r) {
               if (l == 0) ans = s[r];
               else ans = s[r] - s[l-1];
           }else {
               if (l == 0) ans = s[n-1] + s[r];
               else ans = s[n-1] - s[l-1] + s[r];
           }
           cout << ans << endl;
       }
    }

    return 0;
}
