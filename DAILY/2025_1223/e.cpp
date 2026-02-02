#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for(int i=0;i<x;i++)
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;

    ll ans = 0;
    map<ll, ll> mp;
    auto func = [&](auto func, ll x) -> ll{
        if (x == 1 || x == 0) return 0;
        if (mp.count(x)){
            return mp[x];
        }

        ll y = x/2, z = (x+1)/2;

        ll y_res = 0, z_res = 0;
        if (y >=  2)  y_res = func(func, y) + y;
        else  y_res = func(func,y);
        if (z >=  2)  z_res = func(func, z) + z;
        else  z_res = func(func,z);
        ll sum = y_res + z_res;

        mp[x] = sum;
        return sum;
    };
    ans = func(func, n) + n;


    cout << ans << endl;


    return 0;
}
