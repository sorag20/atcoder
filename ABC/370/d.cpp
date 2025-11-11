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
    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> rowSet(h);
    vector<set<ll>> colSet(w);
    rep(i,h)rep(j,w)
    {
        rowSet[i].insert(j);
        colSet[j].insert(i);
    }
    auto erase = [&](ll r, ll c) {
        rowSet[r].erase(c);
        colSet[c].erase(r);
    };

    rep(i,q) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        {
            auto it = rowSet[r].lower_bound(c);
            if (it != rowSet[r].end() && *it == c) {
                erase(r, c);
                continue;
            } else{
                if (it != rowSet[r].end()) {
                    erase(r, *it);
                }
                auto it2 = rowSet[r].lower_bound(c);
                if (it2 != rowSet[r].begin()) {
                    it2--;
                    erase(r, *it2);
                }
            }
        }
        {
            auto it = colSet[c].lower_bound(r);
            if (it != colSet[c].end()) {
                erase(*it, c);
            }
            auto it2 = colSet[c].lower_bound(r);
            if (it2 != colSet[c].begin()) {
                it2--;
                erase(*it2, c);
            }
        }
    }
    ll ans = 0;
    rep(i,h){
        ans += rowSet[i].size();
    }
    cout << ans << endl;
    
    return 0;
}
