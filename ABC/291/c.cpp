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
    int n; cin>>n;
    vector<int> a(n+1),ans(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--){
      int cnt=0;
      for(int j=i+i;j<=n;j+=i){
         if(ans[j]==1) cnt^=ans[j];
      }
      ans[i]=cnt^a[i];
    }
    vector<int> c;
    for(int i=1;i<=n;i++){
       if(ans[i]==1) c.push_back(i);
    }
    cout<<c.size()<<endl;
    if(c.size()==0) return 0;
    for(auto v:c){
      cout<<v<<' ';
    }
    cout<<endl;
   return 0;
}
