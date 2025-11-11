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
using mint=modint998244353;
bool f(int x){
    int cnt=0;
for(int i=1;i*i<=x;i++){
if(x%i==0) cnt++;
else if(x%(x/i)==0 and x/i!=i) cnt++;
}
if(cnt%2==1) return 1;
return 0;

}

int main()
{
  int n,m; cin>>n>>m;
  
return 0;
}
