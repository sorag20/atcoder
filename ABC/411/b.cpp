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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<ll> d(n), s(n);
    rep(i, n-1) {
        cin >> d[i];
    }
    s[0] = d[0];
    for (int i = 1; i < n; i++) {
        s[i] = s[i - 1] + d[i - 1];
    }
    rep(i,n-1){
        for (int j = i + 1; j < n; j++) {
            cout << s[j] - s[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
