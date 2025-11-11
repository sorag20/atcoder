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
    vector<string> s(h);
    rep(i, h) {
        cin >> s[i];
    }
    vector<lP> a;
    queue<P> q;
    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == 'E') {
                   q.push({i, j});
                }
            }
        }
    if (q.empty()) {
        rep(i, h) {
            cout << s[i] << endl;
        }
        return 0;
    }
    vector<string> ans(h, string(w, '0'));
    while (!q.empty()) {
        P p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if (x > 0  && s[x-1][y] != '#' && s[x-1][y] != 'E' && ans[x-1][y] == '0') {
            ans[x-1][y] = 'v';
            q.push({x-1, y});
        }
        if (x < h-1  && s[x+1][y] != '#'  && s[x+1][y] != 'E' && ans[x+1][y] == '0') {
            ans[x+1][y] = '^';
            q.push({x+1, y});
        }
        if (y > 0  && s[x][y-1] != '#'  && s[x][y-1] != 'E' && ans[x][y-1] == '0') {
            ans[x][y-1] = '>';
            q.push({x, y-1});
        }
        if (y < w-1  && s[x][y+1] != '#'  && s[x][y+1] != 'E' && ans[x][y+1] == '0') {
            ans[x][y+1] = '<';
            q.push({x, y+1});
        }
    }

    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == 'E') {
                cout << 'E';
            } else if (s[i][j] == '#') {
                cout << '#';
            } else {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }


    return 0;
}
