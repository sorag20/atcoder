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

int main()
{
    //freopen("input.txt", "r", stdin);

    string s, t;
    cin >> s >> t;
    int tn = t.size(), sn = s.size();
    vector<bool> ans(tn+1, true);

    auto judge = [&](string x, string y) -> void {
        bool ok = true;
        rep(i,y.size()) {
            if (x[i] != y[i] && x[i] != '?' && y[i] != '?') {
                ans[i+1] = false;
                ok = false;
            }
            if (!ok) ans[i+1] = false;
        }
        return;
    };

    rep(ri,2) {
        judge(s,t);

        reverse(all(s));
        reverse(all(t));
        reverse(all(ans));
    }

    rep(i,tn+1) {
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
