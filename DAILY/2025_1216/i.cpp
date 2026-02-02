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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,m;
    cin >> n >> m;
    vector<ll> x(n), y(n);
    rep(i,n) cin>>x[i];
    rep(i,n) cin>>y[i];
    vector<tuple<ll, ll, ll>> e(m);
    rep(i,m) {
        ll a, b, z;
        cin>>a>>b>>z;
        a--;b--;
        e[i] = {z, a, b};
    }
    ll const INF = 1e18;
    ll ans = INF;

    rep(use_air, 2) {
        rep(use_sea, 2) {
            vector<tuple<ll, ll, ll>> ne = e;
            ll n_cnt = n;
            if (use_air) {
                n_cnt++;
                rep(i,n) {
                    ne.eb(x[i], n_cnt -1 , i);
                }
            }
            if (use_sea) {
                n_cnt++;
                rep(i,n) {
                    ne.eb(y[i], n_cnt-1, i);
                }
            }

            sort(all(ne));
            dsu f(n_cnt);
            ll cost_sum = 0, cnt = 0;
            for (auto[cost, a, b] : ne) {
                if (f.same(a,b)) continue;
                f.merge(a,b);
                cost_sum += cost;
                cnt++;
            }
            if(cnt == n_cnt - 1) chmin(ans, cost_sum);
        } 
    }

    cout << ans << endl;

    return 0;
}
