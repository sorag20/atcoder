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
    freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    dsu ds(n+1);
    vector<ll> start;
    rep(i,n) {
        ll a,b;
        cin>> a>>b;
        if (a == 0 && b == 0) start.pb(i+1);
        else {
            ds.merge(a,i+1);
            ds.merge(b,i+1);
        }
    }
    ll ans = 0;
    set<ll> used_leader;
    for(auto i: start) {
        auto leader = ds.leader(i);
        if (used_leader.find(leader) != used_leader.end()) continue;
        used_leader.insert(leader);
        ans += ds.size(leader);
    }
    cout << ans <<endl;

    return 0;
}
