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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> abc(m);
    rep(i,m) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        abc[i] = make_tuple(c,a,b);
    }
    sort(all(abc));
    dsu uf(n);
    ll ans = 0;
    rep(i,m) {
        ll c,a,b;
        tie(c,a,b) = abc[i];
        if(uf.same(a,b)) {
            if (c > 0) {
                ans += c;
            continue;
            }
        }
        uf.merge(a,b);
    }
    cout << ans << endl;

    return 0;
}
