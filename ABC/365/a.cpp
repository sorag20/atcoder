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
    if (n%4 !=0) {
        cout << 365 << endl;
    } else if(n%4 ==0 && n%100 != 0) {
        cout << 366 << endl;
    } else if(n%4 ==0 && n%100 == 0 && n%400 != 0) {
        cout << 365 << endl;
    } else if(n%4 ==0 && n%100 == 0 && n%400 == 0) {
        cout << 366 << endl;
    }

    return 0;
}
