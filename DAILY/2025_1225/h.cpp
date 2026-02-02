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
const P pair1[] = {{-1, 0}, {-1, 0}, {-1, 0}, {0, -1}, {0, 1}, {0, -1}};
const P pair2[] = {{0, -1}, {1, 0}, {0, 1}, {1, 0}, {1, 0}, {0, 1}};
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int main()
{
    //freopen("input.txt", "r", stdin);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin>>s[i];
    auto available = [&](P x) ->bool {
        if (x.first < 0 || x.first >= h || x.second < 0|| x.second >= w) return false;
        if (s[x.first][x.second] == '#') return false;
        return true;
    };

    auto plus = [&](P x, P y) -> P {
        return make_pair(x.first+ y.first,x.second + y.second);
    };

    auto getId = [&](int i, int j) ->int {
        return i * w + j;
    };
    dsu f(h*w);

    rep(i,h)rep(j,w) {
        if (s[i][j] != '.') continue;
        if (j+1 < w && s[i][j+1] == '.') {
            f.merge(getId(i,j), getId(i,j+1));
        }
        if (i+1 < h && s[i + 1][j] == '.') {
            f.merge(getId(i,j), getId(i + 1, j));
        }
    }

    P start;
    rep(i,h)rep(j,w) {
        if (s[i][j] == 'S') start = {i,j};
    }

    rep(i,6) {
        P point1 = plus(pair1[i],start), point2 = plus(pair2[i], start);
        if (!available(point1) || !available(point2)) continue;
        int point1_id = getId(point1.first, point1.second), point2_id = getId(point2.first, point2.second);
        if (f.same(point1_id, point2_id)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;


    return 0;
}
