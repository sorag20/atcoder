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
    float n;
    cin >> n;
    if (n>= 38.0) {
        cout << 1 << endl;
    } else if (n >= 37.5) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
    return 0;
}
