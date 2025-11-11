#include <bits/stdc++.h>
#include<atcoder/all>
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
using mint=modint998244353;

vector<pair<char, int>> encode(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

string decode(const vector<pair<char, int>>& code) {
    string ret = "";
    for (auto p : code) {
        for (int i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}
int main()
{
  int x,y,z; cin>>x>>y>>z;
  string s; cin>>s;
  vector<pair<char, int>> g=encode(s);
  ll ans=0;
  char now='a';
  for (auto[a,b]:g){
    if(now=='a'){
      if(a=='a'){
        if(b*y>z+x*b){
          now=a;
          ans+=z+x*b;
        }
      }

    }
    if(a!=now and b*y>z+x*b){
      now=a;
      ans+=z+x*b;
    }
    else if(a==now and b*x>z+y*b){
      if(now=='a') now='A';
      else now='a';
      ans+=z+y*b;
    }
    else if(a=='A'){
        if(now=='A'){
      ans+=x*b;
    } 
    else{
      ans+=y*b;
    }
    }
    else if(a=='a'){
        if(now=='A'){
      ans+=y*b;
    } 
    else{
      ans+=x*b;
    }
    }
  }
cout<<ans<<endl;
    return 0;
}
