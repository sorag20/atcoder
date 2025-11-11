#include <bits/stdc++.h>
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

void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);

    ll t;
    cin >> t;
    while(t--){
        ll n,m,x,y;
        cin >> n >> m >> x >> y;
        vector<ll> a(n), b(m);
        rep(i,n) cin >> a[i];
        rep(i,m) cin >> b[i];
        ll ans = 0;
        sort(all(a));
        sort(all(b));
        ans += lower_bound(all(b), x) - b.begin();
        ans += lower_bound(all(a), y) - a.begin();
        cout << ans << endl;

        
    }

    return 0;
}
