#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, m;
    cin >> n >> m;
    vector<ll> e(n);
    rep(i,n) e[i] = i;
    vector<vector<ll>> g1(n), g2(n);
    rep(i,m) {
        ll a, b;
        cin>>a>>b;
        a--;b--;
        g1[a].pb(b);
        g1[b].pb(a);
    }

    rep(i,m) {
        ll a, b;
        cin>>a>>b;
        a--;b--;
        g2[a].pb(b);
        g2[b].pb(a);
    }

    do {
        bool f = true;
        rep(i,n) {
            vector<ll> target1;
            for (auto b:g1[i]) {
                target1.pb(e[b]);
            }
            sort(all(target1));
            vector<ll> target2;
            for (auto x:g2[e[i]]) {
                target2.pb(x);
            }
            sort(all(target2));

            if (target1 != target2) f= false;
        }
        if (f) {
            cout << "Yes" << endl;
            return 0;
        }
    } while(next_permutation(all(e)));

    cout << "No" << endl;

    return 0;
}
