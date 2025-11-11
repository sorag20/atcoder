#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
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
    string t; cin>>t;
    vector<char> c(t.size());
    rep(i,t.size()){
        c[i]=t[i];
    }
rep(i,(int)t.size()/2){
      swap(c[i*2],c[i*2+1]);
}
rep(i,t.size()){
    cout<<c[i];
}
cout<<endl;
    return 0;
}
