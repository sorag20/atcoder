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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll s,a,b,x;
    cin >>s>>a>>b>>x;
    ll ans = 0;
    ll sa = a,sb = b;
    for(int i=1;i<=x;i++) {
        if (sa > 0) {
            ans += s;
            sa--;
        } else if (sb > 0) {
           sb--;
        }
        if (sa == 0 && sb == 0) {
            sa = a;sb = b;
        }
    }
    cout << ans << endl;

    return 0;
}
