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

    ll n;
    cin >> n;
    vector<tuple<ll,ll, int>> a;
    rep(i,n) {
        ll _a, b;
        cin>> _a>> b;
        a.emplace_back(_a, _a + b, i+1);
    }
    sort(all(a), [](const auto& x, const auto& y) {
        auto[x_first, x_second, x_third] = x;
        auto[y_first, y_second, y_third] = y;
        ll x_sum = x_first * (y_second);
        ll y_sum = y_first * (x_second);
        if (x_sum != y_sum) return x_sum > y_sum;  // firstは降順
        return x_third < y_third;  // secondは昇順
    }); 
    rep(i,n) {
        auto[a_first, a_second, a_third] = a[i];
        cout << a_third << ' ';
    }
    cout << endl;

    return 0;
}
