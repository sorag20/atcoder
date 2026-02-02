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
    ll t;
    cin>> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n),b(n);
        rep(i,n) cin>>a[i];
        rep(i,n) cin>>b[i];
        priority_queue<ll> q;
        vector<ll> index(n);
        rep(i,n) index[i] = i;
        sort(all(index), [&](ll x, ll y) {
            return a[x] < a[y];
        });
        ll ans = 1e18, b_cnt = 0;
        for (auto in:index) {
            q.push(b[in]);
            b_cnt += b[in];
            if (q.size() == k + 1) {
                ll b_top = q.top();
                q.pop();
                b_cnt -= b_top;
            }
            if (q.size() == k) {
                chmin(ans, a[in] * b_cnt);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
