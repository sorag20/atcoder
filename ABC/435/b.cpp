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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    ll ans = 0;
    rep(i,n) {
        for (int j = i;j<n;j++) {
            ll sum = 0;
            bool f = true;
            for (int k = i;k <= j;k++) {
                sum += a[k];
            }
            for (int k = i;k <= j;k++) {
                if (sum%a[k] == 0) f = false;
            }
            if (f) {
                ans++;
            }
        }

    }
    cout << ans << endl;

    return 0;
}
