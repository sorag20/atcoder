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

const ll dy[] = {-1, 0, 1};
int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    ll const M = 1e5 + 7;
    vector<lP> x(M+1, {0,0});
    rep(i,n){
        ll t, X, A;
        cin >> t >> X >> A;
        x[t] = {X, A};
    }
    const ll INF = 1e18;
    vector<vector<ll>> dp(M+1, vector<ll>(5, -INF));
    dp[0][0] = 0;
    rep(i,M) {
        rep(j,5) {
            rep(k,3) {
                ll nj = j + dy[k];
                if (nj < 0 || nj >= 5) continue;
                dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]);
            }
        }
            dp[i+1][x[i+1].first] += x[i+1].second;
    }


    ll ans = -INF;
    rep(i,5) chmax(ans, dp[M][i]);
    cout << ans << endl;

    return 0;
}
