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
    string t; cin>>t;
    string s = t.substr(0,n);
    t = t.substr(n);
    reverse(all(t));
    string a = s + t, b = t + s;
    vector<int> za = z_algorithm(a);
    vector<int> zb = z_algorithm(b);
    rep(i,n){
        cout <<i<< endl;
        if (i && za[2*n-i] != i) continue;
        int j = n-i;
        if (zb[2*n-j] != j) continue;
        cout <<"iii"<<i<< endl;

        cout <<"sdfas"<< endl;

        string ans = s.substr(0, i);
        string x=  s.substr(i);
        reverse(all(x));
        ans+=x;
        cout << ans << endl;
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
