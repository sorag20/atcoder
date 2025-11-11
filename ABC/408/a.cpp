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
    ll n,s;
    cin >> n >> s;
    ll pre;
    cin >> pre;
    if (pre > s) {
        cout << "No" << endl;
        return 0;
    }
    bool ok = true;
    rep(i,n-1) {
        ll a;
        cin >> a;
        if (a - pre >= s + 1) {
            ok = false;
        }
        pre = a;
    }
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
