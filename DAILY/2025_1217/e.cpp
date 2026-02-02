#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
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

    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll ans = 0;

    auto is_palindrome = [&](string x) {
        string t = x;
        reverse(all(t));
        return x == t;
    };
    sort(all(s));

    do {
        bool f = true;
        rep(i, n-k + 1) {
            string y = s.substr(i, k);
            if (is_palindrome(y)) f = false;
        }
        if (f) {
            ans++;
        }
    } while(next_permutation(all(s)));

    cout << ans << endl;
    return 0;
}
