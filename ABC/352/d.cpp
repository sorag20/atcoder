#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
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
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> a;
    rep(i,m)
    {
        ll k,c;
        cin >> k >> c;
        vector<ll> b(k);
        rep(j,k) {
            cin >> b[j];
            b[j]--;
        }
        rep(j, k-1) {
            a.push_back({c, b[j], b[j+1]});
        }
        a.push_back({c, b[0], b[k-1]});
    }

    sort(all(a));
    dsu uf(n);
    ll ans = 0;
    for (auto [c, x, y] : a) {
        if (uf.same(x, y)) {
            continue;
        } else {
            ans += c;
            uf.merge(x, y);
        }
    }
    if (uf.size(0) != n) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}
