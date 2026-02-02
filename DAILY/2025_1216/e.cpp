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

    ll h,w;
    cin >> h >> w;
    vector<string> s(h), t(h);
    rep(i,h) {
        cin>>s[i];
    }
    rep(i,h) {
        cin>>t[i];
    }
    map<string,ll> s_map, t_map;
    rep(i, w) {
        string x = "";
        rep(j,h) {
            x+= s[j][i];
        }
        s_map[x]++;
    }
    rep(i, w) {
        string x = "";
        rep(j,h) {
            x+= t[j][i];
        }
        t_map[x]++;
    }
    if (s_map.size() != t_map.size()) {
        cout << "No" << endl;
        return 0;
    }

    for (auto [key,val]:s_map) {
        if (t_map[key] != val) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;


    return 0;
}
