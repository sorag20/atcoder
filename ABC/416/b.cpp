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

int main()
{
    //freopen("input.txt", "r", stdin);

    string s;
    cin >> s;
    string ans = s;
    int dot_start = -1;
    bool found_dot = false;
    rep(i, s.size()) {
        char c = s[i];
        if (c == '.') {
            dot_start = i;
            found_dot = true;
        }
        if (c == '#') {
            if (dot_start != -1) {
                ans[dot_start] = 'o';
                dot_start = -1;
            }
        }
    }
    if (found_dot && (dot_start == -1 || dot_start == s.size() - 1)) {
        if(s[s.size() - 1] != '#') {
            ans[s.size() - 1] = 'o';
        }
    }
    cout << ans << endl;
    return 0;
}
