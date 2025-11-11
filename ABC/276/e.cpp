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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    dsu f(h*w);
    int sx, sy;
    auto getId = [&] (int i, int j) {
        return i * w + j;
    };
    rep(i,h)rep(j,w) {
        if (s[i][j] == 'S') {
            sy = i;sx = j;
            continue;
        } 
        if(s[i][j] != '.') {
            continue;
        }
        rep(k, 4) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w || s[ny][nx] != '.') continue;
            int next_id = getId(ny ,nx);
            int now_id = getId(i , j);
            if (!f.same(now_id, next_id)) f.merge(now_id, next_id);
        }
    }
    rep(i,4) {
        int next_1_y = sy + dy[i];
        int next_1_x = sx + dx[i];
        if (next_1_y < 0 || next_1_y >= h || next_1_x < 0 || next_1_x >= w || s[next_1_y][next_1_x] != '.') continue;
        rep(j, 4) {
            int next_2_y = sy + dy[j];
            int next_2_x = sx + dx[j];
            if (next_2_y < 0 || next_2_y >= h || next_2_x < 0 || next_2_x >= w || s[next_2_y][next_2_x] != '.') continue;
            if (next_1_y == next_2_y && next_1_x == next_2_x) continue;
            int next_1_id = getId(next_1_y, next_1_x);
            int next_2_id = getId(next_2_y, next_2_x);
            if (f.same(next_1_id, next_2_id)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
