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


int main()
{
    ll n;
    cin >> n;
    int m1;
    cin >> m1;
    vector<vector<bool>> h(n, vector<bool>(n));
    vector<vector<bool>> g(n, vector<bool>(n));
    rep(i,m1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    int m2;
    cin >> m2;
    rep(i,m2) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        h[a][b] = 1;
        h[b][a] = 1;
    }

    vector<vector<ll>> a(n);
    rep(i,n)rep(j,n) {
        if (j > i) {
            ll x;
            cin>> x;
            a[i].pb(x);
            a[j].pb(x);
        }
    }

    vector<ll> p(n);
    rep(i,n) {
        p[i] = i;
    }

    ll ans = 1001001001;
    do {
        ll temp = 0;
        rep(i,n)rep(j,i) {
            if(h[i][j] != g[p[i]][p[j]]) {
                temp += a[i][j];
            }
        }
        ans = min(ans, temp);
    } while(next_permutation(all(p)));
    
    cout << ans << endl;
    return 0;
}
