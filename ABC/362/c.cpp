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
    vector<ll> l(n), r(n);
    deque<ll> ans;
    rep(i,n) {
        ll l, r;
        cin >> l >> r;
        if (l>0) {
            ans.push_back(l);
        } else {
            ll tmp = ans.back();
            if (tmp < 0) {
                
            }
        }
    }

    return 0;
}
