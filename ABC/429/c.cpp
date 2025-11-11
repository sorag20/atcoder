#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
#include <stack>
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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> mp;
    rep(i,n) {
        cin>>a[i];
        mp[a[i]]++;
    }
    auto nC3 = [&](ll t) {
        return t*(t-1)*(t-2)/6;
    };
    ll ans = nC3(n);
    if (ans==0) {
        cout <<0<<endl;
        return 0;
    }
    // 全部同じ
    ll mp_cnt = 0;
    for(auto [key,value]: mp) {
        mp_cnt++;
        if (value>=3) {
            ans -= nC3(value);
        }
    }
    // 全部違う
    if (mp_cnt>= 3) {
        for(auto [key,value]: mp) {
            ans-=mp_cnt*value;
        }
    }

    cout << ans << endl;



    return 0;
}
