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
    ll n,a,b,ans=1e18;
    cin >> n>>a>>b;
    string s; cin>>s;
    rep(i,n){
        ll tmp=a*i;
        string t=s;
        string v=t.substr(i,n-i)+t.substr(0,i);
        for(int l=0,r=n-1;;l++,r--){
            if(l>=r) break;
            if(v[l]!=v[r]) tmp+=b;
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
