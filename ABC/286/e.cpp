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

    ll const INF = 1e18;
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<string> s(n);
    vector<vector<lP>> d(n, vector<lP>(n, {INF, INF}));
    vector<vector<lP>> path(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> s[i];
    }

    rep(i,n) {
        rep(j,n) {
            if (s[i][j] == 'Y') {
                d[i][j] = {1, -a[j]};
            }
        }
    }
    auto add = [&](lP x, lP y) {
        return lP(x.first + y.first, x.second + y.second);
    };
    // ワーシャルフロイド法で全点間最短経路を求める
    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], add(d[i][k], d[k][j]));
            }
        }
    }

    int q;
    cin >> q;
    while(q--) {
        ll s, t;
        cin >> s >> t;
        s--; t--;
        if (d[s][t].first == INF) {
            cout << "Impossible" << endl;
        } else {
            cout << d[s][t].first << " " << -d[s][t].second + a[s] << endl;
        }

    }

    return 0;
}
