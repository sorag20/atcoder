#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for(int i=0;i<x;i++)
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,m;
    cin >> n>>m;
    ll ans = 0;
    set<lP> st;
    rep(i,m) {
        ll r,c;
        cin>>r>>c;
        r--;c--;
        
        if(st.find({r,c}) == st.end() && st.find({r+1,c}) == st.end() && st.find({r,c+1}) == st.end() && st.find({r+1,c+1}) == st.end()) {
            ans++;
            st.insert({r,c});
            st.insert({r+1,c});
            st.insert({r,c+1});
            st.insert({r+1,c+1});
        }
    }
cout << ans << endl;
    return 0;
}
