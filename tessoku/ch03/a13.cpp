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

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll res = 0;
    ll right = 0;
    auto check = [&](ll l, ll r) -> bool {
        if (a[r] <= a[l] + k) return true;
        return false;
    };
    rep(left, n) {
        while (right < n && check(left, right)) {
            right++;
        }

        // 2.区間の現在の長さ
        res += (right - left);
        res--;
        if (right == left) {
            right++;
        } else {
        // 減らす処理
        }
    }
    /*
        rep(i,n) {
            int pos = lower_bound(a.begin() + i + 1, a.end(), a[i] + k) - a.begin();
            cout << pos << ' ' << i << endl;
            ans += pos - i - 1;
            if (pos != n && a[pos] == a[i]+k) ans++;
        }
    */


    cout << res << endl;
    return 0;
}
