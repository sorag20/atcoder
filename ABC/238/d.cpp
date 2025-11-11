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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

// 桁DP
int main()
{
    //freopen("input.txt", "r", stdin);

    ll t;
    cin >> t;
    while(t--) {
        ll a, s;
        cin >> a >> s;
        map<pair<ll,ll>, bool> mp;
        auto f = [&](auto f, ll a, ll s) {
            if (!s) return a == 0;
            auto p = make_pair(a, s);
            if (mp.count(p)) return mp[p];
            rep(x,2)rep(y,2) {
                if ((x&y) != (a&1)) continue;
                if (s - x - y < 0) continue;
                if ((s - x - y) % 2 != 0) continue;
                // なぜs-x-yなのかわからない
                if (f(f, a>>1, (s - x - y)>> 1)) return mp[p] = true;
            }
            return mp[p] = false;
        };
        if (f(f, a, s)) cout << "Yes" << endl;
        else cout << "No" << endl;

    }

    return 0;
}
