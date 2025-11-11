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
    int n;
    cin >> n;
    vector<string> s(n);
    int m = 0;
    rep(i, n) {
        cin >> s[i];
        m= max(m, (int)s[i].size());
    }
    rep(i,n) {
        while (s[i].size() < m) {
            s[i] += "*";
        }
    }
    vector<string> ans(m);
    rep(i,m) {
        rep(j,n) {
            ans[i] += s[n-j-1][i];
        }
    }
    rep(i,m) {
        rep(j,n) {
            int index = 0;
            rep(j,ans[i].size()) {
                if (ans[i][j] != '*') {
                    index = j;
                }
            }
            ans[i] = ans[i].substr(0, index+1);
        }
    }
    rep(i,m) {
        cout << ans[i] << endl;
    }


    return 0;
}
