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
using mint = modint998244353;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n,m,k;
    cin>>n>>m>>k;
    if (k == 0) {
        mint ans = mint(m).pow(n);
        cout << ans.val() << endl;
        return 0;
    }
    vector<mint> dp(m, 1);
    for (int i = 1; i < n ; i++) {
        vector<mint> ndp(m);
        swap(dp, ndp);
        vector<mint> s(m+1);
        rep(j, m) s[j+1] = s[j] + ndp[j];
        auto sum = [&s](int l, int r) {
            if (l > r) return mint(0);
            return s[r + 1] - s[l];
        };
        rep(j, m) {
            dp[j] = sum(0, j - k) + sum(j + k, m - 1);
        }
    }

    mint ans = 0;
    rep(i, m) ans += dp[i];
    cout << ans.val() << endl;
    return 0;
}
