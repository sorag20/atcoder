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

    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    set<lP> st;
    rep(i,n) {
        cin >> x[i] >> y[i];
        st.insert({x[i], y[i]});
    }
    ll ans = 0;
    rep(i,n)rep(j,n) {
        ll xi = x[i], xj = x[j];
        ll yi = y[i], yj = y[j];
        if (xi < xj && yi > yj) {
            if (st.find({xj, yi}) != st.end() && st.find({xi, yj}) != st.end()){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
