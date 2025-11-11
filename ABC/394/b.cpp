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

int main()
{
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) {
        cin >> s[i];
    }
    sort(all(s), [](string a, string b) {
        return a.size() < b.size();
    });
    rep(i,n) {
        cout << s[i];
    }
    cout << endl;
    
    return 0;
}
