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
    ll n, q;
    cin >> n >> q;
    vector<ll> hato2B(n);
    vector<ll> H2B(n);
    vector<ll> B2H(n);
    rep(i,n) {
        hato2B[i] = i;
        H2B[i] = i;
        B2H[i] = i;
    }
    rep(i,q) {
        ll t;
        cin >> t;
        if (t ==1) {
            ll a, b;
            cin >> a >> b;
            a--; b--;
            hato2B[a] = H2B[b];
        } else if (t == 2) {
            ll a, b;
            cin >>  a >> b;
            a--; b--;
            swap(H2B[a], H2B[b]);
            B2H[H2B[a]] = a;
            B2H[H2B[b]] = b;
         } else if (t == 3) {
            ll a;
            cin >>  a;
            a--;
            cout << B2H[hato2B[a]] + 1 << endl;
        }
    }
    
    return 0;
}
