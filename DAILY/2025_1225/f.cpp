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

int main()
{
    //freopen("input.txt", "r", stdin);

    string s;
    cin >> s;
    auto judge = [&](string x) -> bool {
        string t = x;
        reverse(all(t));
        return x == t;
    };
    if (judge(s)) {
        cout << "Yes" << endl;
        return 0;
    }
    int n = s.size();
    int start = 0, end = n;
    rep(i,n) {
        if (s[i] != 'a') {
            start = i;
            break;
        }
    }
    for (int i = n- 1;i >= 0;i--) {
        if (s[i] != 'a') {
            end = i;
            break;
        }
    }
    //cout << n - end - 1  << " " << start << endl;

    if (n - end - 1 < start) {
        cout << "No" << endl;
        return 0;
    }
    //cout << start << " " << end << endl;
    string target = s.substr(start, end + 1- start);
    //cout << target << endl;
    if (judge(target)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
