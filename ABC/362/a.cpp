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
    ll r,g,b;
    cin >> r>>g>>b;
    string c;
    cin >> c;
    ll ans = 0;
    if (c == "Red")
    {
        ans = min(g, b);
    } else if (c =="Green") {
        ans = min(r, b);
    } else {
        ans = min(r, g);
    }
    cout << ans << endl;

    return 0;
}
