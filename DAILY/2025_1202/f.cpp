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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<set<ll>> a(10);
    rep(i,n) {
        ll now = 0;
        rep(j,10) {
            int current = s[i][j] - '0';
            ll before = now;
            if (a[current].find(now) != a[current].end()) {
                while(1) {
                    ll temp = now+10;
                    if (a[current].find(temp) == a[current].end()) {
                        a[current].insert(temp);
                        break;
                    }
                    now += 10;
                }
            } else {
                a[current].insert(now);
            }
            now = before;
            now++;
        }
    }
    ll ans = 1e18;
    rep(i,10) {
        ll max_s = *max_element(all(a[i]));
        chmin(ans,max_s);
    }
    cout << ans << endl;


    return 0;
}
