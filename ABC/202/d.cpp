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
ll c[61][61];

int main()
{
    //freopen("input.txt", "r", stdin);

    ll a, b, k;
    cin >> a >> b >> k;
    c[0][0] = 1;
    // パスカルの三角形
    rep(i,60)rep(j, i + 1) {
        c[i + 1][j] += c[i][j];
        c[i + 1][j + 1] += c[i][j];
    }

    string ans = "";
    while (a > 0 || b > 0) {
        ll x = 0;
        if (a >= 1) x = c[a + b - 1][a - 1];
        if (k <= x) {
            ans += 'a';
            a--;
        } else {
            ans += 'b';
            b--;
            k -= x;
        }
    }

    cout << ans << endl;

    return 0;
}
