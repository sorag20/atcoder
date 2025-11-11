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
    vector<ll> a(n), b;
    rep(i, n) {
        cin >> a[i];
    }
    rep(i,m) {
        b.pb(i+1);
    }
    ll ans = 0;
    while(1) {
        set<ll> s;
        rep(i, a.size()) {
            s.insert(a[i]);
        }
        bool ok = true;
        rep(i, b.size()) {
            if (s.find(b[i]) == s.end()) {
                ok = false;
                break;
            }
        }
        if (!ok) break;
        // aの末尾を削除
        a.pop_back();
        ans++;
        if (a.size() == 0) break;
    }
    cout << ans << endl;

    return 0;
}
