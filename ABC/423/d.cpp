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

    ll n, k;
    cin >> n >> k;
    priority_queue<lP, vector<lP>, greater<lP>> pq;
    ll empty = k;
    ll now = 0;
    rep(i, n) {
        ll a, b, c;
        cin >> a >> b >> c;

        while(pq.size() && pq.top().first <= a) {
            empty+= pq.top().second;
            pq.pop();
        }
        now = max(now, a);

        while(empty < c) {
            empty += pq.top().second;
            now = pq.top().first;
            pq.pop();
        }

        empty -= c;
        pq.push({b + now, c});
        cout << now << endl;
    }

    return 0;
}
