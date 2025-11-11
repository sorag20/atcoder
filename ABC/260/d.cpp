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

    ll n, k;
    cin >> n >>k;
    vector<ll> p(n);
    rep(i,n) {
        cin >> p[i];
        p[i]--;
    }
    set<ll> st;
    vector<ll> next_c(n, -1), num(n), ans(n, -1);
    rep(i,n) {
        auto it = st.lower_bound(p[i]);
        if (it == st.end()) {
            num[p[i]] = 1;
        } else {
            ll M = *it;
            st.erase(M);
            next_c[p[i]] = M;
            num[p[i]] = num[M] + 1;
        }
        st.insert(p[i]);
        if (num[p[i]] == k) {
            st.erase(p[i]);
            ll t = p[i];
            while(t != -1) {
                ans[t] = i + 1;
                t = next_c[t];
            }
        }
    }
    rep(i,n) {
        cout << ans[i] << endl;
    }

    return 0;
}
