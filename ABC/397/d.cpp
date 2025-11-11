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
    for (ll i = 1; i*i*i <n; i++) {
        ll c = n-i*i*i;
        if (c%(3*i) != 0) continue;
        c /= 3*i;
        ll y = (-i + sqrt(i*i+4*c))/2;
        if (y*y + y*i -c == 0) {
            cout << i+y <<' ' << y << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
