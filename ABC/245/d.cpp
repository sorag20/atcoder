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

    ll n,m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<ll> c(n+m + 1);
    rep(i, n + 1) {
        cin >> a[i];
    }
    rep(i, n+m+1) {
        cin >> c[i];
    }
    vector<ll> b(m+1);
    for (int i = m; i >= 0; i--) {
        ll quo = c[n+ i] / a[n];
        b[i] = quo;
        for (int j = 0; j <= n; j++) {
            c[i+ j] -= quo * a[j];
        }
    }
    for (int i = 0 ; i <= m; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
