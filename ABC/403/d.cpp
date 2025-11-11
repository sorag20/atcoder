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
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    const ll M = 1e6+5;
    vector<ll> cnt(M, 0);
    vector<vector<ll>> b(M+1, vector<ll>(2, 0));
    rep(i, n) {
        cin >> a[i];
        cnt[a[i]%d]++;
    }
    ll ans = 0;
    for (int i = 0; i < M; i+=d) {
        if (cnt[i] > 1) {
            ans += cnt[i] * (cnt[i] - 1) / 2;
        }
    }

    return 0;
}
