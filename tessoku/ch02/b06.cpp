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

    ll n, q;
    cin >> n;
    vector<ll> a(n), s(n+1);
    rep(i,n) {
        cin>> a[i];
        s[i] = a[i];
        if (i != 0) {
            s[i] += s[i-1];
        }
    }
    cin >> q;
    rep(i,q) {
        ll l, r;
        cin >> l >> r;
        ll total = r - l + 1;
        l--;r--;
        ll win = 0;
        if (l == 0) win = s[r];
        else win = s[r] - s[l-1];
        ll lose = total - win;
        if (win > lose) {
            cout << "win" << endl;
        } else if (win < lose) {
            cout << "lose" << endl;
        } else {
            cout << "draw" << endl;
        }
    }

    return 0;
}
