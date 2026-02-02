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

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) {
        cin>>a[i];
        if (a[i] != -1) a[i]--;
    }
    vector<ll> g(n);
    ll start = -1;
    rep(i,n) {
        if (a[i] == -1) start = i;
    }
    rep(i,n) {
        if (a[i] != -1) {
            g[a[i]] = i;
        }
    }
    vector<ll> ans;
    ll now = start;
    while(ans.size() < n) {
        ans.pb(now);
        now = g[now];
    }
    for (auto x:ans) {
        cout << x + 1<< " ";
    }
    cout << endl;
    return 0;
}
