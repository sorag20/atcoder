#include <bits/stdc++.h>
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
vector<pair<char, int>> encode(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
int main()
{
    ll n;
    cin >> n;
    rep(i,n) {
        string s, p;
        cin >> s >> p;
        vector<pair<char, int>> s1 = encode(s);
        vector<pair<char, int>> s2 = encode(p);
        if (s1.size() != s2.size()) {
            cout << "NO" << endl;
            continue;
        }
        bool ok = true;
        for (int j = 0; j < s1.size(); j++) {
            if (s1[j].first != s2[j].first) {
                ok = false;
                break;
            }
            if (s2[j].second > s1[j].second * 2 || s2[j].second < s1[j].second) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
