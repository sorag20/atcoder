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

    int n, m;
    cin>> n >>m;
    scc_graph g(n);
    set<int> st;
    vector<vector<ll>> to(n);
    rep(i,m) {
        int u,v;
        cin>>u>>v;
        u--;v--;
        g.add_edge(u,v);
        to[u].pb(v);
    }
    ll ans = 0;
    auto grp = g.scc();
    int s = grp.size();
    vector<bool> dp(s);
    vector<int> groups(n);

    rep(i,s) {
        for (auto x:grp[i]) {
            groups[x] = i;
        }
    }

    for (int i = s-1;i >= 0;i--) {
        if (grp[i].size() >= 2) dp[i] = true;
        else {
            for (auto x:grp[i]) {
                for (auto v: to[x]) {
                    if (dp[groups[v]]) dp[i] = true;
                }
            }
        }
    }

    rep(i,s) {
        for (auto x:grp[i]) {
            if (dp[i]) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
