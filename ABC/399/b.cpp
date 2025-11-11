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
    ll n;
    cin >> n;
    vector<lP> a(n);
    rep(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(gall(a));
    ll r = 1;
    ll pre = a[0].first;
    vector<ll> ans(n, -1);
    ans[a[0].second] = 1;
    ll cnt = 1;
    queue<ll> q;
    for (int i = 1; i < n; i++) {
        //cout << a[i].first << " " << pre << endl;
        if (a[i].first == pre) {
            //cout << pre << " " << a[i].second << endl;
            ans[a[i].second] = r;
            cnt++;
        } else {
            r += cnt;
            ans[a[i].second] = r;
            cnt = 1;
            pre = a[i].first;
        }
        /*
        rep(k, n) {
            cout << ans[k] << endl;
        cout << "pre: " << pre << endl;
        }*/
    }
    // cout << "cnt: " << cnt << endl;
    rep(i,n) {
        if (ans[i] == -1) {
            ans[i] = r;
        }
    }
    rep(i, n) {
        cout << ans[i] << endl;
    }
    //cout << ans.size() << endl;


    return 0;
}
