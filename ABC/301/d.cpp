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
    string s;
    cin >> s;
    ll n;
    cin >> n;
    auto ten = [&](string t) {
        ll num = 0;
        rep(i, t.size()) {
            num = num * 2 + t[i] - '0';
        }
        return num;
    };

    auto f = [&](string t) {
        string u = t;
        rep(i, u.size()) {
            if (u[i] == '?') {
                u[i] = '0';
            }
        }
        ll num = ten(u);
        return num <= n;
    };

    if (!f(s)) {
        cout << -1 << endl;
        return 0;
    }


    rep(i, s.size()) {
        string t = s;
        if (t[i] == '?') {
            t[i] = '1';
            if (f(t)) {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
    }
    cout << ten(s) << endl;
    return 0;
}
