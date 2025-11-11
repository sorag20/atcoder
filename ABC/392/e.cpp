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
#define t tuple<ll, ll, ll>
using namespace std;
using namespace atcoder;

int main()
{
    ll n, m;
    cin >> n >> m;
    dsu f(n);

    vector<t> multi_edges;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        if (f.same(a, b)) {
            multi_edges.emplace_back(i, a, b);
        } else {
            f.merge(a, b);
        }
    }
    cout << f.groups().size() -1 << endl;
    set <ll> leaders;
    rep(i, n) {
        leaders.insert(f.leader(i));
    }
    vector<t> ans;
    // すべてが連結するまで、multi_count_mpをもっているエッジの片方を、もう片方につなげる
    while(leaders.size() > 1) {
        auto [i, a, b] = multi_edges.back();
        multi_edges.pop_back();
        int leader_a = f.leader(a); leaders.erase(leader_a);
        int leader_b = *leaders.begin(); leaders.erase(leader_b);
        f.merge(leader_a, leader_b);
        leaders.insert(f.leader(leader_a));
        ans.emplace_back(i+1, a+1, leader_b+1);
    }
    
    for (auto x : ans) {
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
    }

    return 0;
}
