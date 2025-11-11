#include <bits/stdc++.h>
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
#include <algorithm>
#include <cassert>
#include <vector>


int main()
{
  int n,q; cin>>n>>q;
  map<int,priority_queue<int,vector<int>,greater<int>>> mp1;
  map<int,set<int>> mp2;
  rep(i,q){
    int t; cin>>t;
    if(t==1){
      int x,y; cin>>x>>y;
      mp1[y].push(x);
      mp2[x].insert(y);
    }
    else if(t==2){
      int x; cin>>x;
      priority_queue<int,vector<int>,greater<int>> tmp;
       while(!mp1[x].empty()){
        cout<<mp1[x].top()<<' ';
        tmp.push(mp1[x].top());
        mp1[x].pop();
      }
      mp1[x]=tmp;
      cout<<endl;
    }
    else{
      int x; cin>>x;
       for(auto v:mp2[x]){
        cout<<v<<' ';
      }
      cout<<endl;
    }
  }
  

    return 0;
}
