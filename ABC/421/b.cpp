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

    string x,y;
    cin >> x >> y;
    vector<string> v(11);
    v[0] = x;
    v[1] = y;
    for (int i = 2; i <= 10; i++) {
        ll t = stoll(v[i - 1]) + stoll(v[i - 2]);
        string t_s = to_string(t);
        reverse(all(t_s));
        v[i] = t_s;
    }
    int index = 0;
    rep(i,v[9].size()) {
        if (v[9][i] == '0') index++;
        else break;
    }
    for(int i = index; i < v[9].size(); i++) cout << v[9][i];
    cout << endl;

    return 0;
}
