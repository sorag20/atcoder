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
    rep(i,n) cin>> a[i];
    bool f = false;
    for (int i = 0;i < n;i++) {
        for (int j = i+ 1;j < n;j++) {
            for (int k = j+ 1;k < n;k++) {
                if (a[i] + a[j] + a[k] == 1000) f = true;
            }
        }
    }
    if (f) {
        cout <<"Yes" << endl;
    } else {
        cout <<"No" << endl;
    }

    return 0;
}
