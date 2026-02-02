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
    vector<ll> a(n), b(n), c(n) , d(n), e(n*n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,n) cin>>c[i];
    rep(i,n) cin>>d[i];
    set<ll> st;
    rep(i,n) {
        rep(j,n) {
            e[i*n+j] = a[i] + b[j];
            st.insert(c[i]+d[j]);
        }
    }
    rep(i,n*n) {
        if (st.find(k -e[i]) != st.end()) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;


    
    return 0;
}
