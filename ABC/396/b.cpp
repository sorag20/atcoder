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
#include <stack>
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
    stack<ll> s;
    rep(i, 100) {
        s.push(0);
    }
    
    rep(i,q) {
        ll t;
        cin >> t;
        if (t ==1) {
            ll a;
            cin >> a;
            s.push(a);
        } else {

            cout << s.top() << endl;
            s.pop();
        }
    }
    
    return 0;
}
