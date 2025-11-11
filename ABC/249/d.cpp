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
    const int MAX = 200005;
    vector<ll> d(MAX);

    rep(i, n){
        ll a; cin>>a;
        d[a]++;
    }
    ll ans = 0;

    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; j <= MAX/i; j++) {
            ll c = i * j;
            ans += d[i] * d[j] * d[c];
        }
    }
    cout << ans << endl;
     
    return 0;
}
