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
    ll n,m;
    cin >> n>>m;
    set<ll> s;
    rep(i,m) {
        ll a;
        char c;
        cin >> a >> c;
        if (!s.count(a) && c =='M') {
            cout << "Yes" << endl;
            s.insert(a);
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
