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
    ll n,t,p;
    cin >> n >> t >> p;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];
    int cnt = 0;
    rep(i, n)
    {
        if (l[i] >= t) cnt++;
    }
    if (cnt >= p) {
        cout << 0 << endl;
        return 0;
    }
    int tmp = 1;
    while ( tmp<=1000) {
        int cnt = 0;
        rep(i, n)
        {
            l[i] += 1;
        }
        rep(i,n) {
            if (l[i] >= t) cnt++;
        }
        if (cnt >= p) {
            cout << tmp << endl;
            return 0;
        }
        tmp++;
    }

        return 0;
}
