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


vector<pair<char, ll>> encode(const string& str) {
    ll n = (ll)str.size();
    vector<pair<char, ll>> ret;
    for (ll l = 0; l < n;) {
        ll r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

string decode(const vector<pair<char, int>>& code) {
    string ret = "";
    for (auto p : code) {
        for (int i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}


int main()
{
    ll n;
    cin >> n;
    vector<ll> p(n);
    string s= "";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n -1; i++) {
        if (p[i] < p[i + 1]) {
            s += '1';
        } else {
            s += '0';
        }
    }
    vector<pair<char, ll>> code = encode(s);
    ll ans = 0;
    for (int i = 1; i < code.size() - 1; i++) {
        if (code[i].first == '0') {
            ans += code[i-1].second * code[i + 1].second;
        }
    }
    cout << ans << endl;

    return 0;
}
