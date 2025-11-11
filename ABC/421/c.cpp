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

    ll n;
    string s;
    cin >> n >> s;
    ll temp1 = 0, temp2 = 0;
    queue<ll> que, cnt1,cnt2;
    rep(i,2*n) {
        if (i % 2 == 0) {
            cnt1.push(i);
        } else {
            cnt2.push(i);
        }
    }
    rep(i,2*n) {
        if (s[i] == 'A') que.push(i);
    }
    while(!que.empty()) {
        ll a = que.front();
        que.pop();
        ll x = cnt1.front();
        cnt1.pop();
        ll y = cnt2.front();
        cnt2.pop();
        temp1 += abs(a - x);
        temp2 += abs(a - y);
    }
    cout << min(temp1, temp2) << endl;


    return 0;
}
