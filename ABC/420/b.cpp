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

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<string> s(n);
    rep(i,n) {
        cin >> s[i];
    }
    rep(i,m) {
        int cnt_0 = 0, cnt_1 = 0;
        rep(j,n) {
            if (s[j][i] == '0') cnt_0++;
            else cnt_1++;
        }
        bool win_0 = false, win_1 = false;
        if (cnt_0 < cnt_1) win_0 = true;
        else win_1 = true;
        rep(j,n) {
            if (win_0) {
                if (s[j][i] == '0') a[j]++;
            } else {
                if (s[j][i] == '1') a[j]++;
            }
        }
    }

    ll max_a = *max_element(all(a));
    rep(i,n) {
        if (a[i] == max_a) cout << i + 1 << ' ';
    }
    cout << endl;

    return 0;
}
