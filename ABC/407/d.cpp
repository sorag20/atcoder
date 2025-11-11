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

int main()
{
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i,h)rep(j,w) {
        cin >> a[i][j];
    }
    vector<vector<bool>> used (h, vector<bool>(w, false));
    ll ans = 0;
    
    auto dfs = [&](auto dfs, vector<vector<bool>> used, int i, int j) -> void {
        if (j == w) {
            j = 0;
            i++;
        }
        if (i == h) {
            ll cnt = 0;
            rep(k, h) {
                rep(l, w) {
                    if (!used[k][l]) {
                        cnt ^= a[k][l];
                    }
                }
            }
            ans = max(ans, cnt);
            return;
        }
        if (used[i][j]) {
            dfs(dfs, used, i, j+1);
        } else {
            dfs(dfs, used, i, j+1);
            if (j < w - 1 && !used[i][j+1]) {
                used[i][j] = true;
                used[i][j+1] = true;
                dfs(dfs, used, i, j + 1);
                used[i][j] = false;
                used[i][j + 1] = false;
            } 
            if (i < h - 1 && !used[i+1][j]) {
                used[i][j] = true;
                used[i+1][j] = true;
                dfs(dfs, used, i , j + 1);
                used[i][j] = false;
                used[i + 1][j] = false;
            }
        }
    };
    dfs(dfs, used, 0, 0);
    cout << ans << endl;
    return 0;
}
