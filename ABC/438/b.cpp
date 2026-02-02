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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, m;
    cin >> n >> m;
    string s, t;
    cin>> s>> t;
    const ll  INF = 1e18;
    ll ans = INF;
    rep(i,n) {
        if (i + m >n) break;
        ll tmp = 0;
        rep(j,m) {
            if (s[i+j] >= t[j]) tmp += s[i+j] - t[j];
            else tmp += (s[i+j] - '0') + '9' - t[j] + 1;
        }
        chmin(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
