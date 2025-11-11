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

    ll l, q;
    cin >> l >> q;
    set<ll> st;
    st.insert(0);
    st.insert(l);
    rep(i, q) {
        ll c, x;
        cin >> c >> x;
        if (c == 1) {
            st.insert(x);
        } else {
            auto it = st.lower_bound(x);
            if (it == st.end()) {
                cout << l - *prev(it) << endl;
            } else if (it == st.begin()) {
                cout << *it<< endl;
            } else {
                cout << *it - *prev(it) << endl;
            }
        }
    }
    return 0;
}
