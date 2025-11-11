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
    ll a, b, c, d, e, f, g, h, i, j, k, l;
    cin >>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
    bool x = false;
    bool y = false;
    bool z = false;
    if ((a < g && g< d) || (a < j && j < d)){
        x = true;
    }
    if ((b < h && h < e) || (b < k && k < e)){
        y = true;
    }
    if ((c < i && i < f) || (c < l && l < f)){
        z = true;
        
    }

    if ((g < a && a < j) || (g < d && d < j)){
        x = true; 
    }
    if ((h < b && b < k) || (h < e && e < k)){
        y = true; 
    }
    if ((i < c && c < l) || (i < f && f < l)){
        z = true;   
    }
    if (x && y && z){
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
