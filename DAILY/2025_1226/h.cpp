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

    ll t;
    cin >> t;

    while(t--) {
        ll n; cin>>n;
        ll n2 = n*2;
        vector<ll> a(n2);
        rep(i,n2) cin>>a[i];
        priority_queue<ll> que;
        ll ans = 0;
        ans += a[0];
        for (int i = 1;i <n2;) {
            if (i >= n2 || i+1 >= n2) break;
            que.push(a[i]);
            que.push(a[i+1]);
            ll top = que.top();que.pop();
            ans += top;
            i+= 2;
        }
        cout << ans << endl;
    }

    return 0;
}
