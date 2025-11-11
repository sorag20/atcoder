#include <bits/stdc++.h>
#include <atcoder/all>
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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    map<ll,ll> mp;
    set<ll> st_for_ans, st;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]]++;
        st.insert(a[i]);
    }

    rep(i,n+1){
        if (st.find(i) == st.end()) {
            st_for_ans.insert(i);
        }
    }

    rep(k,q) {
        ll i,x;
        cin>>i>>x;
        i--;
        mp[a[i]]--;
        if (mp[a[i]] == 0) {
            st_for_ans.insert(a[i]);
        }
        mp[x]++;
        if (mp[x] == 1) {
            st_for_ans.erase(x);
        }
        a[i] = x;
        cout << *st_for_ans.begin() << endl;
    }
    
    return 0;
}
