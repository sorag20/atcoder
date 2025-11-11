#include <bits/stdc++.h>
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

int main()
{
    ll n;
    cin >> n;
    rep(i,n) {
        string s, t, u;
        cin >> s >> t >> u;
        cout <<s[0] << t[0] << u[0] << endl;
    }
    
    return 0;
}
