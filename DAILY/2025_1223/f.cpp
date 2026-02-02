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
    int n = s.size();
    vector<string> ans;
    while(1) {
        bool g = true;
        rep(i,n) {
            if (s[i] > t[i]) {
                g = false;
                s[i] = t[i];
                ans.pb(s);
            }
        }
        if (g) break;
    }

    while(1) {
        bool g = true;
        for (int i = n-1;i >= 0;i--) {
            if (s[i] < t[i]) {
                g = false;
                s[i] = t[i];
                ans.pb(s);
            }
        }

        if (g) break;
    }

    cout << ans.size() << endl;
    for (auto x:ans) {
        cout << x<< endl;
    }



    return 0;
}
