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
    vector<lP> ab(m);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        ab[i] = {a - b, a};
    }
    sort(all(ab));
    ll ans = 0;
    for (auto [cost, a] : ab) {
        if (n < a) continue;
        ll x = (n - a) / cost + 1;
        ans += x;
        n -= x * cost;
    }

    cout << ans << endl;
    return 0;
}
