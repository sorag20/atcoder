#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
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
using mint = modint998244353;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,m,k;
    cin >> n>>m>>k;
    vector<ll> x(m), y(m);
    rep(i,m) {
        cin>>x[i] >> y[i];
        x[i]--;y[i]--;
    }

    deque<mint> dp(n);
    dp[0] = 1;

    rep(ki, k) {
        vector<mint> val(m);
        rep(i,m) val[i] = dp[x[i]];
        dp.push_front(dp.back());
        dp.pop_back();
        rep(i,m) dp[y[i]] += val[i];
    }


    mint ans;
    rep(i,n) ans+= dp[i];
    cout << ans.val() << endl;

    return 0;
}
