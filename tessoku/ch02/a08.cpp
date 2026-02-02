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

    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> g(h, vector<ll> (w));
    rep(i,h)rep(j,w) {
        cin>>g[i][j];
    }
    rep(i,h){
        rep(j,w) {
            if (j != 0) g[i][j] += g[i][j-1];
        }
    }
    rep(i,w){
        rep(j,h) {
            if (j != 0) g[j][i] += g[j-1][i];
        }
    }
    ll q; cin>> q;
    rep(i,q) {
        ll a, b, c, d;
        cin>> a>> b>> c>> d;
        a--;b--;c--;d--;
        ll ans = 0;
        if (a -1>= 0 && b -1>= 0) {
            ans += g[a-1][b-1];
        }
        ans += g[c][d];
        if (a-1 >= 0) ans -= g[a-1][d];
        if (b-1 >= 0) ans -= g[c][b-1];
        cout << ans << endl;
    }


    return 0;
}
