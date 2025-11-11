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
    int m;
    cin >> m;
    vector<string> s(3);
    rep(i,3) cin >> s[i];
    int ans = INT_MAX;
    rep(i, 300)rep(j, 300)rep(k, 300) {
        if (i == j) continue;
        if (j == k) continue;
        if (k == i) continue;
        if (s[0][i%m] == s[1][j%m] && s[1][j%m] == s[2][k%m]) {
            ans = min(ans, max(i, max(j, k)));
        }
    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}
