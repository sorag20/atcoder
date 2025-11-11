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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    string s;
    cin >> s;
    ll ans = 0;
    vector<ll> m(3);
    vector<ll> x(3);
    rep(i, n) {
        if (s[i] == 'X') x[a[i]]++;
    }
    auto mex = [&](ll a, ll b, ll c) {
        set<ll> s;
        s.insert(a);
        s.insert(b);
        s.insert(c);
        rep(i, 3) {
            if (!s.count(i)) return i;
        }
        return 3;
    };
    rep(i,n) {
        if (s[i] == 'M') {
            m[a[i]]++;
        } else if (s[i] == 'X') {
            x[a[i]]--;
        } else {
            rep(j, 3) {
                rep(k, 3) {
                    ans += mex(a[i], j, k) * m[j] * x[k];
                }
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
