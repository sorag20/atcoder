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
    set <ll> s;
    rep(i, m) {
        ll a;
        cin >> a;
        s.insert(a);
    }
    int cnt = 0;
    set <ll> ans;
    for (int i = 1; i <= n; i++) {
        if (s.find(i) == s.end()) {
            ans.insert(i);
            cnt++;
        }
    }
    if (cnt != 0) {
        cout << cnt << endl;
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << 0 << endl;
        cout << endl;
    }
    return 0;
}
