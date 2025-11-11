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

    ll n, r;
    cin >> n >> r;
    vector<ll> l(n + 1);
    rep(i, n) cin >> l[i + 1];

    ll ans = 0;
    ll min_unlock_index = -1, max_unlock_index = n + 1 ;
    for (int i = 1; i <= n; i++) {
        if (l[i] == 0) {
            min_unlock_index = i;
            break;
        }
    }
    for (int i = n ; i >= 1; i--) {
        if (l[i] == 0) {
            max_unlock_index = i;
            break;
        }
    }
    if (min_unlock_index == -1 && max_unlock_index == n + 1) {
        cout << 0 << endl;
        return 0;
    }
    if (r < min_unlock_index) {
        for (int i = r + 1; i<= max_unlock_index ; i++) {
            if (l[i] == 1) {
                ans+= 2;
            } else {
                ans++;
            }
        }
        cout << ans << endl;
        return 0;
    } else if (r > max_unlock_index) {
        for (int i = r; i>= min_unlock_index ; i--) {
            if (l[i] == 1) {
                ans+= 2;
            } else {
                ans++;
            }
        }
        cout << ans << endl;
        return 0;
    }

    for (int i = r - 1; i>= min_unlock_index ; i--) {
        if (l[i] == 1) {
            ans++;
            l[i] = 0;
        }
    }
    for (int i = min_unlock_index; i <= max_unlock_index; i++) {
        if (l[i] == 1) {
            ans+= 2;
        } else {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
