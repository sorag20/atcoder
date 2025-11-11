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
    ll n, m;
    cin >> n >> m;
    vector<ll> ans(n);
    // 帰ってくるイベント
    v<lP, vector<lP>, greater<lP>> queue;
    // 今いる人
    set<ll> member;

    rep(i,n) {
        member.insert(i);
    }
    rep(i,m) {
        ll t, w, s;
        cin >> t >> w >> s;
        while (!queue.empty() && queue.top().first <= t) {
            auto top = queue.top();
            queue.pop();
            member.insert(top.second);
        }

        if (!member.empty()) {
            auto p = member.begin();
            // 先頭の人を取り出す
            member.erase(p);
            ans[*p] += w;
            queue.push({t + s, *p});
        }
    }

    rep(i,n) {
        cout << ans[i] << endl;
    }
    return 0;
}
