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
    vector<ll> t(n);
    vector<vector<ll>> g(n);
    rep(i,n) {
        ll k;
        cin>> t[i]>>k;
        rep(j,k) {
            ll a;cin>>a;
            a--;
            g[i].pb(a);
        }
    }
    vector<bool> used(n,false);
    auto dfs = [&](auto dfs, ll x) {
        if(used[x]) return;
        used[x] = true;
        for(auto A:g[x]) {
            dfs(dfs,A);
        }
    };
    dfs(dfs,n-1);
    ll ans = 0;
    rep(i,n) {
        if(used[i]) ans += t[i];
    }
    cout << ans << endl;
    return 0;
}
