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
    ll q;
    cin >> q;
    map<ll, ll> mp;
    rep(i, q){
        ll t;
        cin >> t;
        if ( t == 1 || t == 2) {
            ll x;
            cin >> x;
            if (t == 1) {
                mp[x]++;
            } else if (t == 2){
                mp[x]--;
                if (mp[x] == 0) {
                    mp.erase(x);
                }
            }
        } else {
            cout<<mp.size()<<endl;
        }
    }

        return 0;
}
