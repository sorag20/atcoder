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

    ll n,q;
    cin >> n>>q;
    vector<tuple<ll,ll,string>> qs;
    rep(i,q) {
        ll t,p;
        cin>>t>>p;
        string s;
        if (t ==2) {
            cin>>s;
        }
        qs.emplace_back(t,p,s);
    }
    ll target = 0;
    vector<string> st(n+1);
    string ans;
    for(int i = q-1; i>= 0;i--) {
        auto [t,p,s] = qs[i];
        if (t == 1) {
            if (target == p) {
                target = 0;
            }
        } else if (t == 2) {
            if (target == p) {
                reverse(all(s));
                ans+= s;
            }
        } else {
            if (target == 0) {
                target = p;
            }
        }
    }
    reverse(all(ans));
    cout << ans << endl;

    return 0;
}
