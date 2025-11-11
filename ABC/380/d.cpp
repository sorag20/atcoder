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

int f (ll l, ll r, ll k) {
    if (r-l == 1) return 0;
    ll c = (l+r)/2;
    if (k < c) {
        return f(l, c, k);
    } else {
        return f(c, r, k) + 1;
    }
}



int main()
{
    string s;
    ll q;
    cin >> s >> q;
    vector<ll> k(q);
    rep(i, q) cin >> k[i];
    int s_size = s.size();
    rep(i,q) {
        ll K = k[i]-1;
        int si = K%s_size;
        K/=s_size;
        int cnt = f(0, 1ll<<60, K);

        if (cnt % 2 == 0) {
            cout << s[si] << " ";
        } else {
            if (s[si] >= 'a' && s[si] <= 'z') {
                char c = s[si] - 32;
                cout << c << " ";
            } else {
                char c = s[si] + 32;
                cout << c << " ";
            }
        }
    }


    return 0;
}
