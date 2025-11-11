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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    P first = {0, 0};
    first.first = a - c;
    first.second = b - d;
    cout << first.first << " " << first.second << endl;
    
    return 0;
}
