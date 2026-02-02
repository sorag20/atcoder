#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

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
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<ll> p(n);
    rep(i,n) cin>>p[i];
    string t= "";
    rep(i,n-1) {
        if (p[i] < p[i+1]) t+="1";
        else t+= "0";
    }
    vector<pair<char, int>> encoded = encode(t);

    ll ans = 0;
    rep(i,encoded.size()) {
        auto [c, cnt] = encoded[i];
        if (c == '0') {
            ll back_0 = 0, front_0 = 0;
            if (i-1 >= 0) back_0 = encoded[i-1].second;
            if (i+1 <= encoded.size() -1) front_0 = encoded[i+1].second;
            ans += back_0* front_0;
        }
    }

    cout << ans << endl;
    return 0;
}
