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
    double a, b;
    cin >> a >> b;
    double n = a / b;
    int k = (int) a/b;
    double m = n - k;
    if (m > 0.5) {
        cout << k + 1 << endl;
    } else {
        cout << k << endl;
    }


    return 0;
}
