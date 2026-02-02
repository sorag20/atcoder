#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define eb emplace_back
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

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    a.pb(0);
    a.insert(a.begin(), 0);
    n+= 2;
    vector<ll> dpre(n), dsuff(n);
    for (int i = 1;i < n;i++) {
        dpre[i] = min(dpre[i-1] + 1, a[i]);
    }

    for (int i = n-2;i >= 0;i--) {
        dsuff[i] = min(dsuff[i+1] + 1, a[i]);
    }
    ll ans = 0;
    rep(i,n) {
        ll tmp = min(dpre[i], dsuff[i]);
        chmax(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
