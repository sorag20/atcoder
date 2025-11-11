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
using mint=modint1000000007;
const int MAX = 510000;
const int MOD = 1000000007;
int main()
{
    int n,m,h,k;
    cin>>n>>m>>h>>k;
    string s;
    cin>>s;
    set<P> st;
    rep(i,m){
        int c,y; cin>>c>>y;
        st.insert(make_pair(c,y));
    }
    int nowx=0;
    int nowy=0;
    for(int i=0;i<n;i++){
          h--;
          if(h<0){
            cout<<"No"<<endl;
            return 0;
        }
        if(s[i]=='R'){
        nowx++;
        if(st.find(make_pair(nowx,nowy))!=st.end()){
            if(h<k){
                h=k;
                st.erase(make_pair(nowx,nowy));

            }
        }
        }
         if(s[i]=='L'){
             nowx--;
        if(st.find(make_pair(nowx,nowy))!=st.end()){
            if(h<k){
                h=k;
                st.erase(make_pair(nowx,nowy));

            }
        }
        }
         if(s[i]=='U'){
             nowy++;
        if(st.find(make_pair(nowx,nowy))!=st.end()){
            if(h<k){
                h=k;
                st.erase(make_pair(nowx,nowy));

            }
        }
        }
         if(s[i]=='D'){
             nowy--;
        if(st.find(make_pair(nowx,nowy))!=st.end()){
            if(h<k){
                h=k;
                st.erase(make_pair(nowx,nowy));
            }
        }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
