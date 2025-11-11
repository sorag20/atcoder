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
    ll n,k;
    cin >> n>> k;
    vector<ll> r(n);
    ll sum = 0;
    ll max_r = 0;
    rep(i, n)
    {
        cin >> r[i];
        max_r = max(max_r, r[i]);
    }
    ll max_cnt = max_r;
    ll min_cnt = 1;
    rep(i,n-1) {
        max_cnt = max_cnt*10+max_r;
        min_cnt = min_cnt*10+1;
    }
    vector<ll> ans;
    for (ll i = min_cnt; i <= max_cnt; i++)
    {
        string s = to_string(i);
        bool flag = false;
        int sum = 0;
        rep(j, s.size())
        {
            int int_s = s[j]-48;
            sum += int_s;
            if (int_s> r[j] || int_s == 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        if (sum%k == 0) {
            ans.pb(i);
        }
    }
    for(auto a: ans) {
        string s = to_string(a);
        rep(i, s.size()) {
            cout<<s[i];
            if (i != s.size()-1) {
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}


