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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<pair<string, ll>> s(n);
    rep(i,n) {
        cin >> s[i].first;
        s[i].second = i;
    }
    stable_sort(all(s));
    auto check = [&](string x, string y) -> ll{
        ll cnt = 0;
        ll len = min(x.size(), y.size());
        rep(i,len) {
            if (x[i] == y[i]) {
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    };

    vector<ll> ans(n);
    rep(i,n-1) {
        chmax(ans[s[i].second], check(s[i].first, s[i+1].first));
        chmax(ans[s[i+1].second], check(s[i].first, s[i+1].first));
    }
    rep(i,n) {
        cout << ans[i] << endl;
    }
    return 0;
}
