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
    int const M = 100005;
    vector<ll> g(M);
    vector<vector<ll>> divs(M);
    for (int i = 1; i < M; i++) {
        for (int j = i*2; j < M; j += i) {
            divs[j].push_back(i);
        }
    }
    for (int i = 1; i < M; i++) {
        set<ll> s;
        for (auto d : divs[i]) {
            s.insert(g[d]);
        }
        while (s.count(g[i])) {
            g[i]++;
        }
    }

    ll n;
    cin >> n;
    ll x = 0;
    rep(i,n) {
        ll a;
        cin >> a;
        x ^= g[a];
    }
    if (x) {
        cout << "Anna" << endl;
    } else {
        cout << "Bruno" << endl;
    }
    
    return 0;
}
