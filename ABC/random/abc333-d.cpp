#include <iostream>
#include <atcoder/all>
#include <vector>
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

int X[4] = {1, 0, -1, 0};
int Y[4] = {0, 1, 0, -1};

int main()
{
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) {
        cin >> s[i];
    }
    map<char, char> next;
    next['s'] = 'n';
    next['n'] = 'u';
    next['u'] = 'k';
    next['k'] = 'e';
    next['e'] = 's';
    vector<vector<ll>> seen(h, vector<ll>(w, 0));
    // 深さ優先探索
    auto dfs = [&](auto &dfs, ll x, ll y) -> void {
        seen[x][y] = 1;
        rep(i,4) {
            ll nx = x + X[i];
            ll ny = y + Y[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                continue;
            }
            if (s[nx][ny] == next[s[x][y]] && seen[nx][ny] == 0) {
                dfs(dfs, nx, ny);
            }
        }
    };
    dfs (dfs, 0, 0);

    if (seen[h-1][w-1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }



    return 0;
}
