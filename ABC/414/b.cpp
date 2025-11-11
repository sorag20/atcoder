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
    cin >> n;
    string ans = "";
    ll temp = 0;
    rep(i,n) {
        char c;
        ll x;
        cin >> c >> x;
        if (x > 100) {
            cout << "Too Long" << endl;
            return 0;
        }
        temp += x;
        if (temp > 100) {
            cout << "Too Long" << endl;
            return 0;
        }
        rep(j,x) {
            ans += c;
        }
        if (ans.size() > 100) {
            cout << "Too Long" << endl;
            return 0;
        }
    }
    if (ans.size() > 100) {
        cout << "Too Long" << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}
