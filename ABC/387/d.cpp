#include <bits/stdc++.h>
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

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 1001001001;
    rep(par, 2)
    {
        vector dist(h, vector<int>(w, -1));
        queue<P> q;
        auto push = [&](int i, int j, int d)
        {
            if (i< 0 || i >= h || j < 0 || j >= w)
                return;
            if (s[i][j] == '#')
                return;
            if (dist[i][j] != -1)
                return;
            dist[i][j] = d;
            q.emplace(i, j);
        };

        rep(i,h)rep(j,w) if(s[i][j] == 'S') push(i, j, 0);
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            int d = dist[i][j];
            if (s[i][j] == 'G')
            {
                ans = min(ans, d);
            }
            if ((i+j)%2 == par) {
                push(i+1, j, d+1);
                push(i-1, j, d+1);
            } else {
                push(i, j+1, d+1);
                push(i, j-1, d+1);
            }
        }
    }
    if (ans == 1001001001)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
