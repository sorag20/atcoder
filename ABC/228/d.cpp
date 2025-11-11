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
    const ll n = 1<<20;
    ll q;
    cin >> q;
    set<ll> st;
    rep(i,n) st.insert(i);
    map<ll, ll> mp;
    while (q--)
    {
        ll t, x;
        cin >> t >> x;
        if (t == 1)
        {
            ll index = x%n;
            auto it = st.lower_bound(index);
            if (it == st.end())
            {
                it = st.begin();
            }
            mp[*it] = x;
            st.erase(it);
        }
        else
        {
            ll index = x%n;
            if (mp.find(index) == mp.end())
            {
                cout << -1 << endl;
            } else {
                cout << mp[index] << endl;
            }
        }
    }
    
    return 0;
}
