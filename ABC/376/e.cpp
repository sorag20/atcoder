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
    ll t;
    cin >> t;
    rep(i, t) {
        ll n, k;
        cin >> n >> k;
        vector<lP> ab(n);
        rep(j, n) {
            cin >> ab[j].first;
        }
        rep(j, n) {
            cin >> ab[j].second;
        }
        ll ans = 1e18;
        sort(all(ab));
        priority_queue<ll> q;
        ll sum = 0;
        rep(j, n) {
            ll a = ab[j].first;
            ll b = ab[j].second;
            if (q.size() >= k - 1) {
                ans = min(ans, (sum + b) * a);
            }

            sum += b;
            q.push(b);
            if (q.size() == k) {
                sum -= q.top();
                q.pop();
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
