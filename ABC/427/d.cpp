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

ll dp[2*10^5+5][12];
int main()
{
    //freopen("input.txt", "r", stdin);

    ll t;
    cin >> t;
    while(t--) {
        ll n,m,k;
        cin >>n>>m>>k;
        string s;
        cin>>s;
        vector<vector<ll>> g(n);
        rep(i,m) {
            ll u, v;
            cin>>u>>v;
            u--;v--;
            g[u].pb(v);
        }
        vector<vector<ll>> dp(2*k + 1, vector<ll> (n));
        rep(i,n) {
            if (s[i] == 'A') dp[2 * k][i] = 1;
        }
        for (int i = 2 * k - 1;i>= 0;i--) {
            rep(v,n) {
                dp[i][v] = 0;
                for (int u:g[v]) {
                    if (!dp[i+1][u]) dp[i][v] = 1;
                }
            }
        }
        if (dp[0][0] == 1) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }

    return 0;
}
