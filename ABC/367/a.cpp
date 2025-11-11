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
    ll a,b,c;
    cin >> a >> b >> c;
    if (b > c) {
        if( a>=c && a<= b) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    } else {
        if ((0<=a && a<=b) || (c<=a && a<=24)){
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }

    
    return 0;
}
