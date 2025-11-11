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
    int n = s.size();
    P ans = {0, 0}; // {count of '.', count of '#'}
    rep(i,n) {
        if (s[i] == '#') {
            if (ans.first > 0) {
                ans.second = i + 1;
                cout << ans.first << "," << ans.second << endl;
                ans = {0, 0}; // reset for next segment
            } else {
                ans.first = i + 1;
            }
        }
    }

    return 0;
}
