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
    ll n;
    cin >> n;
    map<ll, map<ll, ll>> mp;
    vector<ll> K(n);
    rep(i,n) {
        ll k;
        cin >> k;
        K[i] = k;
        rep(j,k) {
            ll a;
            cin >> a;
            mp[i][a]++;
        }
    }
    // n個から2つ選ぶのでnC2通りを全探索
    // 確率の最大値
    double ans = 0;
    rep(i,n) {
        rep(j,n) {
            if (i == j) continue;
            double temp = 0;
            for (auto x : mp[i]) {
                if (mp[j].find(x.first) != mp[j].end()) {
                    double i_prob = (double)x.second / K[i];
                    double j_prob = (double)mp[j][x.first] / K[j];
                    temp += i_prob * j_prob;
                }
            }
                ans = max(ans, temp);
        }
    }
    printf("%.10f\n", ans);

    return 0;
}
