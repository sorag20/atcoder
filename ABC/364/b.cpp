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
    ll h,w;
    cin >> h >> w;
    ll si, sj;
    cin >> si >> sj;
    si--; sj--;
    vector<string> s(h);
    rep(i,h) {
        cin >> s[i];
    }
    string x;
    cin >> x;
    rep(i,x.size()) {
        if (x[i]== 'L') {
            if (sj > 0 && s[si][sj-1] != '#') {
                sj--;
            }
        } else if (x[i] == 'R') {
            if (sj < w-1 && s[si][sj+1] != '#') {
                sj++;
            }
        } else if (x[i] == 'U') {
            if (si > 0 && s[si-1][sj] != '#') {
                si--;
            }
        } else if (x[i] == 'D') {
            if (si < h-1 && s[si+1][sj] != '#') {
                si++;
            }
        }
    }
    cout << si+1 << " " << sj+1 << endl;

    return 0;
}
