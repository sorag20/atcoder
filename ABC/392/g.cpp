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
    int n;
    cin >> n;
    int MX = 1000001;
    vector<int> a(MX);
    vector<int> s(n);
    rep(i,n) {
        cin>> s[i];
        a[s[i]]++;
    }
    auto ac = convolution(a, a);
    for (int x : s) ac[x*2]--;
    rep (i, ac.size()) ac[i] /= 2;

    ll ans = 0;
    for (int x : s) {
        ans += ac[2*x];
    }
    cout << ans <<endl;
    
    return 0;
}
