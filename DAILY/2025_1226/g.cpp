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

    ll n;
    cin >> n;
    ll const INF = 2e5+5;
    vector<ll> s(INF);
    rep(i,n) {
        ll l, r;
        cin>>l >> r;
        s[l]++;
        s[r]--;
    }
    for (int i = 1;i <= 2e5;i++) {
        s[i+1] += s[i];
    }

    bool plus = false;
    vector<lP> ans;
    lP now;
    for (int i = 1;i <= 2e5;i++) {
        if (s[i] > 0) {
            if (!plus) {
                plus= true;
                now.first = i;
            }
        } else {
            if (plus) {
                plus = false;
                now.second = i;
                ans.pb(now);
                now = {-1, -1};
            }
        }
    }

    for (auto x:ans) {
        cout << x.first << " " << x.second << endl;
    }




    return 0;
}
