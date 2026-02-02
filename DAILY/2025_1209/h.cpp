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
using mint = modint998244353;

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,m,k;
    cin >> n>>m>>k;
    vector<vector<mint>> dp(k+1, vector<mint> (n+1));
    dp[0][0] = 1;
    //　逆元
    mint im = mint(m).inv();
    mint ans = 0;
    rep(i,k){
        rep(j,n) {
            for (int l = 1;l <= m ;l++) {
                int nj = j + l;
                if (nj > n) nj = 2*n-(j+l);
                if (nj == n) ans += dp[i][j]*im;
                else dp[i+1][nj] += dp[i][j]*im;
            }
        }
    }

    cout << ans.val() <<endl;


    return 0;
}
