#include <bits/stdc++.h>
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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);

    ll t;
    cin >> t;
    while (t--) {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    priority_queue<ll> pq;
    rep(i, n) {
        cin >> a[i];
        if (a[i] <= c) {
            pq.push(a[i]);
        }
    }

    ll ans = n, cnt = 1;
    while (!pq.empty()) {
        ll x = pq.top();
        pq.pop();
        if (x * cnt <= c) {
            ans--;
            cnt*=2;
        }
    }

    cout << ans << endl;
}

    return 0;
}
