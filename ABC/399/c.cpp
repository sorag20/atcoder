
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
    dsu uf(n);
    ll ans = 0;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if (uf.same(a, b)) {
            ans++;
        } else {
            uf.merge(a, b);
        }
    }
    cout << ans << endl;
    
    return 0;
}
