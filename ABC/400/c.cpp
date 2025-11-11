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

    ll ans = 0;
    for (ll i = 1; i <= 59; i++) {
        ll m = n;
        rep(j, i) {
            m /= 2;
        }
        if (m == 0) break;
        m= sqrtl(m);
        ans += (m+1)/2;
    }
    cout << ans << endl;


    return 0;
}
