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
        ll n;
        cin >> n;
        vector<ll> a_odd, a_even;
        rep(i, n) {
            ll a;
            cin >> a;
            if (a % 2 == 0) a_even.pb(a);
            else a_odd.pb(a);
        }
        ll ans = 0;
        bool exist_odd = false;
        if (a_odd.size() != 0) exist_odd = true;
        if (exist_odd){
            for (ll a : a_even) ans += a;
            sort(gall(a_odd));
            ans += a_odd[0];
            ll able_cnt = (a_odd.size() - 1)/2;
            for (int i = 1; i<= able_cnt;i++) ans += a_odd[i];
            cout << ans << endl;
        }
        else {
            cout << ans << endl;
        }
    }

    return 0;
}
