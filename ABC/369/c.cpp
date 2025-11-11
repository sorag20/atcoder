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
    string s, t;
    cin >> s >> t;
    ll cnt = 0;
    vector<string> x;
    rep(i,s.size())
    {
        if (s[i] > t[i]) {
            cnt++;
            s = s.substr(0, i) + t.substr(i, 1) + s.substr(i+1);
            x.pb(s);
        }
    }
    for (int i = s.size()-1; i >= 0; i--)
    {
        if (s[i] != t[i]) {
            cnt++;
            s = s.substr(0, i) + t.substr(i, 1) + s.substr(i+1);
            x.pb(s);
        }
    }

    cout<< cnt << endl;
    rep(i, x.size())
    {
        cout << x[i] << endl;
    }

    return 0;
}
