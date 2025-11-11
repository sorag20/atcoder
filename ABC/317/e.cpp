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

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};

int main()
{
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<bool>> g(h, vector<bool>(w, 0));
    P start, goal;
    rep(i,h) {
        rep(j,w) {
            if (s[i][j] == 'S') start = P(i, j);
            if (s[i][j] == 'G') goal = P(i, j);
        }
    }
    rep(i,h) {
        rep(j,w) {
            //cout << s[i][j] << " ";
            int type = 0;
            if (s[i][j] == '.' || s[i][j] == 'S' || s[i][j] == 'G') {
                continue;
            }
            if (s[i][j] == '#') {
                g[i][j] = true;
                continue;
            }
            if (s[i][j] == '^') {
                type = 0;
                g[i][j] = true;
            } else if (s[i][j] == '>') {
                type = 1;
                g[i][j] = true;
            } else if (s[i][j] == 'v') {
                type = 2;
                g[i][j] = true;
            } else if (s[i][j] == '<') {
                type = 3;
                g[i][j] = true;
            }
            int i_i = i;
            int j_j = j;
            while(1) {
                int ni = i_i+di[type];
                int nj = j_j+dj[type];
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) break;
                if (s[ni][nj] == '^' || s[ni][nj] == '>' || s[ni][nj] == 'v' || s[ni][nj] == '<' || s[ni][nj] == '#' || s[ni][nj] == 'S' || s[ni][nj] == 'G') {
                    break;
                } else {
                    g[ni][nj] = true;
                    i_i = ni;
                    j_j = nj;
                }
            }
        }
        //cout << endl;
    }
    /*
    rep(i,h) {
        rep(j,w) {
            if (g[i][j]) cout << "#";
            else cout << ".";
        }
        cout << endl;
    }
*/
    queue<P> q;
    q.push(start);
    vector<vector<ll>> dist(h, vector<ll>(w, -1));
    dist[start.first][start.second] = 0;
    while(!q.empty()) {
        P p = q.front(); q.pop();
        int i = p.first;
        int j = p.second;
        rep(k,4) {
            int ni = i+di[k];
            int nj = j+dj[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || g[ni][nj] || dist[ni][nj] != -1) continue;
            dist[ni][nj] = dist[i][j]+1;
            q.push(P(ni, nj));
        }
    }
    
    if (dist[goal.first][goal.second] == -1) cout << -1 << endl;
    else cout << dist[goal.first][goal.second] << endl;
    return 0;
}
