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

    ll n;
    cin >> n;
    vector<ll> l(n);
    rep(i, n) cin >> l[i];
    vector<bool> enter_1(n + 1, false), enter_2(n + 1, false);
    enter_1[0] = true;
    enter_1[n] = true;
    for (int i = 0; i < n; i++) {
        if (l[i] == 1) break;
        enter_1[i + 1] = true;
    }
    for (int i = n - 1 ; i >= 0; i--) {
        if (l[i] == 1) break;
        enter_2[i] = true;
    }
    ll ans = 0;
    rep(i,n + 1) {
        if (!enter_1[i] && !enter_2[i]) ans++;
    }
    cout << ans << endl;

    return 0;
}
