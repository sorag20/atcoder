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
const int dx[] = {1, 0};
const int dy[] = {0, 1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll h, w;
    cin >> h >>w;
    vector<vector<ll>> g(h,vector<ll> (w));
    rep(i,h) {
        rep(j,w){
            cin>>g[i][j];
        }
    }

    ll ans = 0;
    vector<vector<bool>> visited(h, vector<bool> (w));
    set<ll> st;
    auto dfs = [&](auto dfs, ll i, ll j) -> void {
        visited[i][j] = true;
        st.insert(g[i][j]);
        if (i == h -1 && j == w - 1) {
            ans++;
            visited[i][j] = false;
            st.erase(g[i][j]);
            return;
        }
        rep(k,2){
            ll ni = i + dx[k];
            ll nj = j + dy[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w ) continue;
            if (st.find(g[ni][nj]) == st.end() && !visited[ni][nj]) {
                dfs(dfs, ni,nj);
            }
        }
        visited[i][j] = false;
        st.erase(g[i][j]);
    };
    dfs(dfs,0,0);

    cout << ans << endl;


    return 0;
}
