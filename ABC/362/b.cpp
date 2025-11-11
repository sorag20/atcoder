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
    ll xa,ya,xb,yb,xc,yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;

    if ((((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb)) + ((xa-xc)*(xa-xc) + (ya-yc)*(ya-yc))) == ((xb-xc)*(xb-xc) + (yb-yc)*(yb-yc)) ) {
        cout << "Yes" << endl;
    } else if ((((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb)) + ((xb-xc)*(xb-xc) + (yb-yc)*(yb-yc))) == ((xa-xc)*(xa-xc) + (ya-yc)*(ya-yc)) ) {
        cout << "Yes" << endl;
    } else if ((((xa-xc)*(xa-xc) + (ya-yc)*(ya-yc)) + ((xb-xc)*(xb-xc) + (yb-yc)*(yb-yc))) == ((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb)) ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
