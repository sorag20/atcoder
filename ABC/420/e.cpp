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
    freopen("input.txt", "r", stdin);

    ll n, q;
    cin >> n >> q;
    dsu uf(n);
    vector<set<ll>> st(n);
    rep(i,q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll u, v;
            cin >> u >> v;
            u--;
            v--;
            if (!uf.same(u, v)) {
                uf.merge(u, v);
            }
        } else if (t == 2) {
            ll u;
            cin >> u;
            u--;
            ll leader = uf.leader(u);

            if(st[leader].empty()) {
                set<ll> s;
                s.insert(u);
                st[leader] = s;
            } else if (st[leader].count(u) == 0) {
                st[leader].insert(u);
            } else {
                st[leader].erase(u);
                if (st[leader].size() == 0) {
                    st[leader] = {};
                }
            }
        } else {
            ll v;
            cin >> v;
            v--;
            ll leader = uf.leader(v);
            if(st[leader].empty() || st[leader].size() == 0) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }

    return 0;
}
