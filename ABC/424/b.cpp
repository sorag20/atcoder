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

    int n,m,k;
    cin >> n>>m>>k;
    map<ll, vector<ll>> mp;
    vector<ll> ans;
    rep(i,k) {
        int a,b;
        cin>>a>>b;
        mp[a].pb(b);
        if (mp[a].size()== m) ans.pb(a);
    }
    for (auto c : ans) {
        cout << c << ' ';
    }

    return 0;
}
