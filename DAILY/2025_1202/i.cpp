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
const ll INF = 1e19;
int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    rep(i,m) {
        ll u,v;cin>>u>>v;
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    {
        vector<bool> visited(n);
        auto dfs = [&](auto dfs, ll u)-> void 
        {
            visited[u] = true;
            for(auto v:g[u]) {
                if (visited[v]) continue;
                dfs(dfs, v);
                printf("%lld %lld\n", u+1 , v+1);
            }
        };
        dfs(dfs,0);
    }
    {
        queue<ll> que;
        vector<bool> visited(n);
        visited[0] = true;
        que.push(0);
        while(que.size()) {
            ll u = que.front();
            que.pop();
            for (auto v :g[u]) {
                if (visited[v]) continue;
                visited[v] = true;
                que.push(v);
                printf("%lld %lld\n", u+1 , v+1);
            }
        }
    }


    return 0;
}
