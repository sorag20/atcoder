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

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n, vector<ll>(n, 0));
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    vector<ll> p(n,0);
    rep(i,n) p[i] = i;

    ll ans = 0;
    do {
        bool ok = true;
        rep(i,n) {
            if (i == p[i] || i == p[p[i]]) ok = false;
        }
        if (!ok) continue;
        ll cnt = 0;
        rep(i,n) {
            cnt += g[p[i]][i];
        }
        ans = max(ans, cnt);
    } while (next_permutation(all(p)));

    cout << m - ans * 2 + n << endl;

    return 0;
}
