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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<pair<char, int>> s1 = encode(s);
        if (s1.size() == 1 || s1.size() == 2  || (s1.size() == 3 && s1[0].first == '0' && s1[2].first  == '0')) {
            cout << 0 << endl;
            continue;
        }
        int sum = 0;
        int max1 = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i].first == '1') {
                sum += s1[i].second;
                max1 = max(max1, s1[i].second);
            }
        }
        cout << sum - max1 << endl;
    }

    return 0;
}
