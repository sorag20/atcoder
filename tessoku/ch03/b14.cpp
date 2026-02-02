#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define eb emplace_back
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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b, c,d;
    rep(i,n) cin>> a[i];
    set<ll> st;
    rep(i,n/2) {
        c.pb(a[i]);
    }
    for(int i = n/2;i < n;i ++) {
        d.pb(a[i]);
    }

    rep(i,1<<c.size()) {
        ll cnt = 0;
        rep(j, c.size()) {
            if (i & (1 << j)) cnt += c[j];
        }
        b.pb(cnt);
    }
    rep(i,1<<d.size()) {
        ll cnt = 0;
        rep(j,d.size()) {
            if (i & (1 << j)) cnt += d[j];
        }
        st.insert(cnt);
    }

    for(auto b_:b) {
        if (st.find(k-b_) != st.end()) {
            cout <<"Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;




    return 0;
}
