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
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    dsu uf(1e6);
    rep(i,n) {
        if (a[i] != a[n - i - 1]) {
            if (!uf.same(a[i], a[n - i - 1])) {
                uf.merge(a[i], a[n - i - 1]);
            }
        }
    }
    ll ans = 0;
    auto groups = uf.groups();
    for (auto& group : groups) {
        ll size = group.size();
        ans += size - 1;
    }
    cout << ans << endl;

    return 0;
}
