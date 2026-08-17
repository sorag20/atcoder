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
// 

auto isPalindrome(string s, ll a) -> bool {
    ll x = stoll(s);
    string t = "";
    while (x) {
        t += '0' + x% a;
        x /= a;
    }
    string r = t;
    reverse(all(r));
    return t == r;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    ll a, n;
    cin >> a >> n;
    ll ans = 0;
    auto check = [&](ll x) {
        if (x <= n && isPalindrome(to_string(x), a)) {
            ans+= x;
        }
    };

    for (ll i = 1; i <= 1e6; i++) {
        string s = to_string(i);

        string t = s;
        reverse(all(t));
        string r = s + t;
        ll x = stoll(r);
        check(x);


        r.erase(r.begin() + r.size()/2);
        x = stoll(r);
        check(x);
    }
    cout << ans << endl;

    return 0;
}
