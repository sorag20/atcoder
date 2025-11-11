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
    dsu d(n);
    rep(i,m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        d.merge(a, b);
    }
    ll k;
    cin>>k;
    set<lP> s;
    rep(i,k) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        ll C = d.leader(x), D = d.leader(y);
        if (C > D) swap(C, D);
        s.insert({C, D});
    }
    ll q;
    cin >> q;
    rep(i,q) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        ll A = d.leader(a), B = d.leader(b);
        if (A > B) swap(A, B);
        if (s.count({A, B})) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}
