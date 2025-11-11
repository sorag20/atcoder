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
    string x;
    cin >> x;
    string ans = "";
    ll temp = 0;
    rep(i,x.size()) {
        temp += x[i] - '0';
    }
    ll cuml = temp;
    string temp_s = to_string(temp);
    ans += temp_s[temp_s.size() - 1];
    for (int i = x.size() - 1; i >= 1; i--) {
        temp /= 10;
        temp += cuml - (x[i] - '0');
        cuml -= (x[i] - '0');
        ans += to_string(temp)[to_string(temp).size() - 1];
        cout << ans << endl;
    }
    if (temp/10 != 0) {
        ans += to_string(temp/10)[to_string(temp/10).size() - 1];
    }

    reverse(all(ans));
    cout << ans << endl;

    return 0;
}
