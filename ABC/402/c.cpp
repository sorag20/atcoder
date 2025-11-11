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

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<set<ll>> material(n);
    rep(i,m) {
        ll k;
        cin >> k;
        rep(j,k) {
            ll a;
            cin >> a;
            a--;
            material[a].insert(i);
        }
    }
    vector<ll> b(n);
    rep(i, n) {
        cin >> b[i];
        b[i]--;
    }
    vector<ll> ans(n);
    set<ll> used;
    for (int i = n - 1; i >= 0; i--) {
        ll before = used.size();
        for (auto j : material[b[i]]) {
            if (used.find(j) == used.end()) {
                used.insert(j);
            }
        }
        ans[i] = used.size() - before;
        //cout << ans[i] << endl;
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
       cnt += ans[i];
       cout << cnt << endl;
    }
    
    return 0;
}
