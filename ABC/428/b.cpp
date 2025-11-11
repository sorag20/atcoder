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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, k;
    string s;
    cin >> n>>k;
    cin>> s;
    map<string,ll> mp;
    rep(i,n){
        if (i + k - 1 < n) {
        string t = s.substr(i,k);
        mp[t]++;
        }
    }
    ll mx = 0;
    rep(i,n){
        if (i + k - 1 < n) {

        string t = s.substr(i,k);
        mx = max(mx,mp[t]);
        }
    }
    set<string> ans;
    rep(i,n){
        if (i + k - 1 < n) {

        string t = s.substr(i,k);
        if (mp[t] == mx) ans.insert(t);
        }
    }
    cout << mx <<endl;
    for(auto S:ans) {
        cout << S << ' ';
    }



    return 0;
}
