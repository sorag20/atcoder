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
    cin >> n>> m;
    vector<ll> dig(n);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    vector<vector<ll>> vec(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        vec[a].pb(b);
        dig[b]++;
    }
    rep(i, n) {
        if (dig[i] == 0) {
            pq.push(i);
        }
    }
    vector<ll> ans;
    while (!pq.empty()) {
        ll x = pq.top();
        pq.pop();
        ans.pb(x);
        for (auto y : vec[x]) {
            dig[y]--;
            if (dig[y] == 0) {
                pq.push(y);
            }
        }
    }
    cout << ans.size() << endl;
    if (ans.size() != n) {
        cout << -1 << endl;
    } else {
        for (auto x : ans) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}
