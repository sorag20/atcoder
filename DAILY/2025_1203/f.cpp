#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    rep(i,n) cin>>a[i];
    rep(i,n-1) cin>>b[i];
    sort(all(a));
    sort(all(b));
    const ll INF = 1e9+5;
    ll wa = 0, ok = INF;
    while(wa + 1 < ok) {
        ll mid = (wa+ok)/2;
        bool f = true;
        vector<ll> c = b;
        c.pb(mid);
        sort(all(c));
        rep(i,n) {
            if (a[i] > c[i]) f = false;
        }
        if (f) ok = mid;
        else wa = mid;
    }
    if (ok == INF) cout << -1 <<endl;
    else cout << ok <<endl;

    return 0;
}
