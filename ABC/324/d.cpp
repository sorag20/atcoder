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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> v(10);
    ll cnt_0 = 0;
    rep(i,n) {
        if (s[i] == '0') {
            cnt_0++;
        }
        v[s[i] - '0']++;
    }
    ll ans =0;
    for (ll i = 0; i*i <= 9999999999999; i++) {
        ll x = i*i;
        string s2 = to_string(x);
        if (s2.size() > n) {
            break;
        }
        vector<ll> v2(10);
        for (auto c : s2) {
            v2[c - '0']++;
        }
        v2[0] += s.size() - s2.size();
        if (v == v2) {
            ans++;
        }
       
    }
    cout << ans << endl;
    return 0;
}
