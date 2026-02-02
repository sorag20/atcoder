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

    ll n,x,y;
    cin >> n >> x>> y;
    vector<ll> a(n);
    rep(i,n) cin>> a[i];
    sort(all(a));
    ll w = a[0] * y;
    ll ans = 0;
    ll y_x = y - x;
    rep(i,n) {
        ll now_w = a[i] * y;
        ll diff = now_w - w;
        if (diff%y_x != 0) {
            cout << -1 << endl;
            return 0;
        }
        ll temp = a[i] - diff/y_x;
        if (temp < 0) {
            cout << -1 << endl;
            return 0;
        }
        ans += temp;
    }

    cout << ans << endl;

    return 0;
}
