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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,k;
    cin >> n>>k;
    vector<ll> a(n), s(n), d(n);
    rep(i,n) {
        cin>>a[i];
    }
    // sort(all(a));  // ソートを削除
    rep(i,n) {
        s[i] = a[i];
        if (i != 0) s[i] += s[i-1];
    }

    auto check = [&](ll l, ll r) -> bool {
        if (l == 0) {
            if (s[r] <= k) return true;
        } else {
            if (s[r] - s[l-1] <= k) return true;
        }
        return false;
    };
    ll res = 0;
    rep(left, n) {
        if (left == 0) d[left] = left - 1;
        else d[left] = max((ll)left - 1, d[left-1]);

        while (d[left] + 1< n && check(left, d[left] + 1)) {
            d[left]++;
        }

    }
    rep(left, n) {
        res += d[left] - left +1;
    
    }
    cout << res << endl;



    return 0;
}
