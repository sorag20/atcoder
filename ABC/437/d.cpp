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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using mint = modint998244353;
int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    vector<lP> ab;
    rep(i,n) {
        cin>>a[i];
        ab.eb(a[i], 0);
    }
    rep(i,m) {
        cin>>b[i];
        ab.eb(b[i], 1);
    }

    sort(all(ab));
    mint ans = 0;

    rep(k,2) {
        ll sum = 0, cnt = 0;
        for (auto [x, type]: ab) {
            if (type == 0) {
                sum += x;
                cnt++;
            } else {
                ans += cnt * x - sum;
            }
        }
        for (auto& [x, type]: ab) x*= -1;
        reverse(all(ab));
    }


    cout << ans.val() << endl;



    return 0;
}
