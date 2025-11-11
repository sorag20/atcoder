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
// or加算
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> edges;
    rep(i,m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges.emplace_back(a, b, c);
    }

    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        dsu d(n);
        for (auto[a, b, c] : edges) {
            if (((c >> i)|(ans>>i)) != ans>>i) continue;
            d.merge(a, b);
        }
        if (!d.same(0, n - 1)) {
            ans |= (1 << i);
        }
    }
    cout << ans << endl;

    return 0;
}
