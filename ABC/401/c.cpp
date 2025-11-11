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
using mint = modint;
int main()
{
    ll n, k;
    cin >> n >> k;
    mint::set_mod(1000000000);
    vector<mint> a(n+1);
    vector<mint> s(n+2);
    for(int i=0;i<n+1;i++) {
        if (i>=0 && i<k) {
            a[i] = 1;
        } else {
            a[i] = s[i];
        }
        if (i>=0 && i<k) {
            s[i+1] = a[i]+ s[i];
        } else {
            s[i+1] = s[i] +a[i]- a[i-k];
        }
    }


    cout << a[n].val() << endl;
    
    return 0;
}
