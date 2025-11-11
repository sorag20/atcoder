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

    ll M = 1e6;
    vector<ll> d(M+1, 0);
    for (int p = 2; p <= M; ++p) {
        if (d[p] != 0) continue;
        for (int q = p; q <= M; q += p) {
            d[q]++;
        }
    }

    rep(i,n) {
        ll  a;
        cin >> a;
        ll x = sqrtl(a);
        while (x > 0) {
            if (d[x] != 2) {
                x--;
            } else {
                cout << x * x << endl;
                break;
            }
        }
    }
    
    return 0;
}
