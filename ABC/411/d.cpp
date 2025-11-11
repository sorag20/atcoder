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
    vector<string> s(n, "");
    vector<bool> pc_used(n, false);
    bool server_not_empty = false;
    string ans= "";
    rep(i,q) {
        ll t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p;
            p--;
            if (!server_not_empty) {
                s[p] = "";
            } else {
                s[p] = ans;
                pc_used[p] = true;
            }
        } else if (t == 2) {
            int p;string x;
            cin >> p >> x;
            p--;
            s[p] += x;
            pc_used[p] = true;
        } else {
            int p;
            cin >> p;
            p--;
            if (pc_used[p]) {
                ans = s[p];
                server_not_empty = true;
            } else {
                ans = "";
            }
        }
    }
    cout << ans << endl;

    return 0;
}
