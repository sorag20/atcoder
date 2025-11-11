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
    cin >> n>> m;
    vector<ll> b(n), w(m);
    rep(i,n) cin >> b[i];
    rep(i,m) cin >> w[i];
    sort(gall(b));
    sort(gall(w));
    ll ans = 0;
    rep(i,n) {
        ll temp = b[i];
        ll temp2 = 0;
        if (i < m) {
            temp2 += w[i];
        }
        if (temp > 0) {
            ans += temp;
            if (temp2 > 0) {
                ans += temp2;
            }
        } else if (temp + temp2 > 0) {
            ans += temp + temp2;
        }
    }
    cout << ans << endl;
    
    return 0;
}
