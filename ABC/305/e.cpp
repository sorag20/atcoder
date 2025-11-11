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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> g(n);
    rep(i,m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<lP> ph;
    rep(i,k) {
        ll p, h;
        cin >> p >> h;
        p--;
        ph.pb({p, h});
    }

    set<ll> ans;
    rep(i,k) {
        vector<bool> checked(n, false);
        ll p = ph[i].first, h = ph[i].second;
        //cout << p << ' ' << h << endl;
        checked[p] = true;
        ans.insert(p);
        queue<lP> q;
        q.push({p, h});
        while (!q.empty()) {
            lP now = q.front();
            q.pop();
            now.second--;
            //cout << now.first << ' ' << now.second << endl;
            if (now.second  == -1) break;
            for (ll next : g[
                now.first
            ]) {
                if (checked[next]) continue;
                checked[next] = true;
                ans.insert(next);
                q.push({next, now.second});
            }
        }
    }
    cout << ans.size() << endl;
    for (ll a : ans) {
        cout << a+1 << ' ';
    }
    return 0;
}
