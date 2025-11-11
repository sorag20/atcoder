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
    ll q;
    cin >> q;
    deque<ll> d;
    rep(i,q) {
        ll n;
        cin >> n;
        if (n == 1) {
            int x;
            cin >> x;
            d.push_back(x);
        } else {
            int x = d.front();
            d.pop_front();
            cout << x << endl;
        }
    }
    
    return 0;
}
