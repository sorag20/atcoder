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
        ll n,m;
        cin >> n >> m;
        ll ans = 0;
        ll current_time = 0, current_pos = 0;
        rep(i,n) {
            ll a, b;
            cin >> a >> b;
            if (current_pos == 0) {
                if (b == 0) {
                    if ((a-current_time) % 2 == 0) {
                        ans += (a-current_time);
                        current_time = a;
                        current_pos = 0;
                    } else {
                        ans += (a-current_time) - 1;
                        current_time = a;
                        current_pos = 0;
                    }
                } else {
                    if ((a-current_time) % 2 == 0) {
                        ans += (a-current_time) - 1;
                        current_time = a;
                        current_pos = 1;
                    } else {
                        ans += (a-current_time);
                        current_time = a ;
                        current_pos = 1;
                    }
                }
            } else {
                if (b == 0) {
                    if ((a-current_time) % 2 == 0) {
                        ans += (a-current_time) -1;
                        current_time = a;
                        current_pos = 0;
                    } else {
                        ans += (a-current_time);
                        current_time = a;
                        current_pos = 0;
                    }
                } else {
                    if ((a-current_time) % 2 == 0) {
                        ans += (a-current_time);
                        current_time = a;
                        current_pos = 1;
                    } else {
                        ans += (a-current_time) - 1;
                        current_time = a;
                        current_pos = 1;
                    }
                }
            }
        }
        ans += (m - current_time);
        cout << ans << endl;
        
    }

    return 0;
}
