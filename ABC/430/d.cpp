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

    ll n;
    cin >> n;
    set<lP> st;
    vector<ll> dist(n+2);
    st.emplace(0,0);
    st.emplace(1e10,n+1);
    ll ans = 1e10;
    dist[0] = 1e10;

    auto update = [&](lP pair, ll x) {
        ans -= dist[pair.second];
        chmin(dist[pair.second], (ll)abs(pair.first - x));
        ans += dist[pair.second];
    };


    rep(i,n) {
        ll x;
        cin>>x;
        auto it = st.emplace(x, i+1).first;
        lP pre = *prev(it), nex = *next(it);
        dist[it->second] = min(abs(pre.first - x), abs(nex.first - x));
        ans += dist[it->second] ;

        update(pre, x);
        update(nex, x);

        cout << ans << endl;
    }


    return 0;
}
