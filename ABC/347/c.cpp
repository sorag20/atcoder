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

    ll n,a,b;
    cin >> n>>a>>b;
    vector<ll> d(n);
    rep(i,n) {
        cin>>d[i];
    }
    ll k = a+b;
    rep(i,n) {
        d[i]= d[i]%k;
    }
    sort(all(d));
    d.pb(d[0] + a + b);
    bool flag = false;
    rep(i,n) {
        if (d[i+1] - d[i] >= b + 1) flag = true;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
