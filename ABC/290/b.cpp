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
int main()
{
     int n; cin>>n;
     vector<vector<int>> a(n+1,vector<int> (n+1));
     vector<vector<int>> b(n+1,vector<int> (n+1));
     for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
      cin>>a[i][j];
     }
     }
      for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
      cin>>b[i][j];
     }
      }

    bool f=0;
    rep(z,4){
      bool g=1;
      for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
      int x=i,y=j;
      int nx=i,ny=j;
      rep(k,z){
         nx=n+1-y;ny=x;
         x=nx;y=ny;
      }
      if(a[i][j]==1){
         if(b[nx][ny]==0) g=0;
      }
     }
      }
      
      if(g) f=1;
    }
     if(f) cout<<"Yes"<<endl;
     else cout<<"No"<<endl;



    return 0;
}
