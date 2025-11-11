#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
#include <set>
#include <queue>
#include<complex>
#include <utility>
#include<string>
#include <map>
#include <regex>
#include<cmath>
#include<ctime>
#include <math.h>
#include<time.h>
#include <random>
#include <algorithm>
#define pb push_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for (int i = 0; i < x; i++)
#define P pair<double, double>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;


int main(){
  int n,m; cin>>n>>m;
  vector<vector<int>> g(n);
  rep(i,m){
    int a,b; cin>>a>>b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
 queue<int> que;
 vector<int> dist(n);
 rep(i,n) dist[i]=-1;
 dist[0]=0;
 que.push(0);
 while(!que.empty()){
  int v=que.front();
  que.pop();
  for(auto c:g[v]){
    if(dist[c]==-1){
    dist[c]=dist[v]+1;
    que.push(c);
  }
 }
 }
 for(int i=0;i<n;i++) {
  cout<<dist[i]<<endl;
 }
 return 0;
}


