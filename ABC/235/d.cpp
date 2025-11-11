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

    ll a, n;
    cin >> a >> n;
    const ll mx = 1e6;
    const ll inf = 1e9;
    vector<ll> dist(mx, inf);
    queue<P> q;
    auto push = [&](ll v, ll d) {
        if (v < 0 || v >= mx) return;
        if (dist[v] != inf) return;
        dist[v] = d;
        q.push({v, d});
    };
    push(1, 0);
    while (!q.empty()) {
        auto [v, d] = q.front(); q.pop();
        push(v * a, d + 1);
        if (v >= 10 && v % 10 != 0) {
            string s = to_string(v);
            rotate(s.begin(), s.begin() + s.size() - 1, s.end());
            push(stoll(s), d + 1);
        }
    }
    if (dist[n] == inf) dist[n] = -1;
    cout << dist[n] << endl;


    return 0;
}
