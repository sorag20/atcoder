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

    ll q;
    cin >> q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    queue<ll> que;

    rep(i,q) {
        int x;
        cin >> x;
        if (x == 1) {
            ll a;
            cin >> a;
            que.push(a);
        } else if (x == 2) {
            if (!pq.empty()) {
                ll a = pq.top();
                pq.pop();
                cout << a << endl;
            } else {
                ll a = que.front();
                cout << a << endl;
                que.pop();
            }
        } else {
            while (!que.empty()) {
                ll a = que.front();
                que.pop();
                pq.push(a);
            }
        }
    }

    return 0;
}
