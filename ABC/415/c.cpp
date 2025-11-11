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
    freopen("input.txt", "r", stdin);

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        queue<ll> q;
        q.push(0);
        ll n2 = 1 << n;
        vector<bool> visited(n2, 0);
        visited[0] = true;

        while(q.size()) {
            ll nt = q.front();
            q.pop();
            rep(i,n) {
                ll t = nt | (1 << i);
                if (nt == t) continue;
                if (s[t-1] == '1') continue;
                if (visited[t]) continue;
                visited[t] = true;
                q.push(t);
            }
        }

        if (visited[n2 - 1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
