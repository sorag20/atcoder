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

    string s;
    cin >> s;
    map<char, int> mp;
    for (auto c : s) {
        mp[c]++;
    }
    char ans = 'a';
    for (auto c : mp) {
        if (c.second == 1) {
            ans = c.first;
            break;
        }
    }
    cout << ans << endl;
    

    return 0;
}
