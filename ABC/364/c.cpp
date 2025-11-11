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
    ll n, x,y;
    cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    vector<lP> c(n), d(n);
    rep(i,n) {
        cin >> a[i];
    }
    rep(i,n) {
        cin >> b[i];
    }
    rep(i,n) {
        c[i] = {a[i], b[i]};
    }
    rep(i,n) {
        d[i] = {b[i], a[i]};
    }
    sort(gall(c));
    sort(gall(d));
    ll a_sum = 0, a_cnt=0, a_tmp=1e18;
    ll b_sum = 0 , b_cnt=0 , b_tmp=1e18;
    rep(i, n)
    {
        a_sum += c[i].first;
        b_sum += c[i].second;
        a_cnt++;
        b_cnt++;
        if (a_sum > x || b_sum > y) {
            a_tmp = a_cnt;
            break;
        }
        if (i == n-1) {
            a_tmp = a_cnt;
        }
    }
    a_sum = 0;
    a_cnt = 0;
    b_sum = 0;
    b_cnt = 0;
    rep(i, n)
    {
        a_sum += d[i].second;
        b_sum += d[i].first;
        a_cnt++;
        b_cnt++;
        if (a_sum > x || b_sum > y) {
            b_tmp =b_cnt;
            break;
        }
        if (i == n-1) {
            b_tmp =  b_cnt;
        }
    }

    cout << min(a_tmp , b_tmp) << endl;

    return 0;
}
