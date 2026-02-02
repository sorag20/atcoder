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

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    map<ll, ll> mp;
    rep(i,n) {
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    int na = a.size();
    vector<ll> s(na);

    rep(i,na) {
        s[i] = mp[a[i]];
        if (i > 0) s[i] += s[i-1];
    }

    ll ans = 0;
    rep(i,na) {
        int pos = lower_bound(all(a), a[i]+ m) - a.begin();
        //if (pos < n && a[i]+ m == a[pos]) pos--;
        pos--;
        ll cnt = 0;
        if (i == 0) cnt = s[pos];
        else cnt = s[pos] - s[i-1];
        chmax(ans, cnt);
    }


    cout << ans << endl;

    return 0;
}
