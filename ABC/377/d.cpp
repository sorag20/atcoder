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
    ll n, m;
    cin >> n >> m;
    vector<ll> maxL(m+1, 0);
    rep(i, n) {
        ll l, r;
        cin >> l >> r;
        maxL[r] = max(maxL[r], l);
    }
    
    int l = 1;
    ll ans = 0;
    for (int r = 1; r <= m; r++) {
        while (l <= maxL[r]) {
            l++;
        }
        ans += r - l + 1;
    }

    cout << ans << endl;
    return 0;
}
