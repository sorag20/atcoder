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

    ll n, q;
    cin >> n >> q;
    vector<bool> x(n+1);
    ll cnt = 0;
    bool h = false;
    rep(i, q) {
        ll a;
        cin>>a;
        a--;
        if (!x[a]) {
            if (a > 0 && a < n - 1 && a != 0&& x[a - 1] && x[a + 1]) cnt--;
            else if ((a == 0 && x[a+1])||(a == n - 1 && a != 0&& x[a - 1]) ||(a > 0 && a < n - 1 && a != 0&& (x[a - 1] || x[a + 1]))) h = true;
            else {
            cnt++;
            }
            x[a] = true;
        } else {
            if (a > 0 && a < n - 1 && a != 0&& x[a - 1] && x[a + 1]) cnt++;
            else if ((a == 0 && x[a + 1])||(a == n - 1 && a != 0&& x[a - 1]) ||(a > 0 && a < n - 1 &&a != 0&& (x[a - 1] || x[a + 1]))) h = false;
            else {
            cnt--;
            }
            x[a] = false;
        }
        cout << cnt << endl;
    }

    return 0;
}
