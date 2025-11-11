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
    int n = s.size();
    reverse(all(s));

    ll ans = 0;
    ll cnt = 0;
    rep(i,n) {
        ll x = s[i] - '0';
        if (x- cnt < 0) {
            ll tem = 10 + x - cnt;
            ans += tem + 1;
            cnt = (cnt + tem) % 10;
        } else {
            ans += x - cnt + 1;
            cnt = ( x) % 10;
        }
    }
    cout << ans << endl;

    return 0;
}
