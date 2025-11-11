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
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, char>> edges;
    rep(i, m)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        edges.emplace_back(x, y, c);
    }
    sort(gall(edges));
    int maxY = 0;
    for (auto [x, y, c] : edges)
    {
        if (c == 'B') {
            maxY = max(maxY, y);
        } else {
            if (y <= maxY) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}
