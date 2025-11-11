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

    ll n,q;
    cin >> n >> q;
    priority_queue<lP> st;
    rep(i,q) {
        ll x, y;
        cin >> x >> y;
        if (st.empty()) {
            cout << x << endl;
            st.push(lP(x, y));
            continue;
        }
        lP top = st.top();
        cout << top.first << " " << top.second << endl;
        if (top.second < x) {
            cout << x << endl;
        }
        else if (top.first < x) {
            cout << x - top.first << endl;
        }
        else {
            cout << 0 << endl;
        }
        st.push(lP(x, y));
    }
    return 0;
}
