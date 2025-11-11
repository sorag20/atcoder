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
//DP
int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    vector<vector<ll>> g(305, vector<ll>(305, LLONG_MAX));
    g[0][0] = 0;
    rep(i,n) {
        ll a, b;
        cin >> a >> b;
        vector<vector<ll>> ng(305, vector<ll>(305, LLONG_MAX));
        rep(i,305) {
            rep(j,305) {
                if (g[i][j] == LLONG_MAX) continue;
                chmin(ng[i][j], g[i][j]);
                chmin(ng[min(x, i + a)][min(y, j + b)], g[i][j] + 1);
            }
        }
        g = ng;
    }
    if (g[x][y] == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << g[x][y] << endl;
    }

    return 0;
}
