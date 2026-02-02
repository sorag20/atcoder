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

    int n;
    cin >> n;
    string s;
    cin>> s;
    ll ans = 1e18;
    rep(ri, 2)
    {
        ll now = 0;
        int ai = 0;
        rep(i,n*2) {
            if (s[i] == 'A') {
                now += abs(i - ai * 2);
                ai++;
            }
        }
        chmin(ans,now);
        reverse(all(s));
    }
    cout << ans << endl;

    return 0;
}
