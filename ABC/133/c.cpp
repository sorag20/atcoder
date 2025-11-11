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
#define rep(i,x) for(int i=0;i<x;i++)
#define ll long long
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;

int main()
{
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> bit(n);

    rep(i,n) {
        ll a;
        cin >> a;
        bit.add(i, a);
    }

    rep(i,q) {
        int t;
        cin >> t;
        if (t == 0) {
            ll x, y;
            cin >> x >> y;
            bit.add(x, y);
        } else {
            ll x, y;
            cin >> x >> y;
            cout << bit.sum(x, y) << endl;
        }
    }
    return 0;
}
