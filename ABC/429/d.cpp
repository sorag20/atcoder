#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
#include <stack>
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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n ,m, c;
    cin >> n >> m >> c;
    vector<ll> a(n);
    rep(i,n) {
        cin>>a[i];
    }
    map<ll, int> mp;
    rep(i,n) {
        mp[a[i]]++;
    }
    vector<pair<ll,int>> d;
    for (auto p:mp) d.emplace_back(p);
    for (auto p:mp) d.emplace_back(p.first + m, p.second);
    int dn = mp.size();
    ll px = d[dn-1].first - m;
    int r = 0, now_cnt = 0;
    ll ans = 0;
    rep(i,dn) {
        while(now_cnt < c) {
            now_cnt += d[r].second;
            r++;
        }
        ans += now_cnt * (d[i].first - px);
        px = d[i].first;
        now_cnt -= d[i].second;
    }
    cout << ans << endl;

    return 0;
}
