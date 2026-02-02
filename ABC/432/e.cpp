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
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) {
        cin>> a[i];
    }
    const int MX = 500005;
    fenwick_tree<ll> tc(MX), ts(MX);
    rep(i,n) {
        tc.add(a[i],1);
        ts.add(a[i],a[i]);
    }
    rep(i,q){
        int t , x, y;
        cin>>t>>x>>y;
        if (t == 1) {
            x--;
            tc.add(a[x],-1);
            ts.add(a[x],-a[x]);
            a[x] = y;
            tc.add(a[x],1);
            ts.add(a[x],a[x]);
        } else {
            ll ans = 0;
            if (x > y) {
                ans = (ll) n* x;
            } else {
                ans += tc.sum(0,x)* x;
                ans += ts.sum(x,y);
                ans += tc.sum(y, MX)* y;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
