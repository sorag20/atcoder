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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<ll> x(n), s(n);
    vector<lP>  xp(n);
    rep(i,n) {
        cin>>x[i];
        xp[i].first = x[i];
    }
    rep(i,n) {
        cin>>xp[i].second;
        s[i] = xp[i].second;
        if (i != 0) {
            s[i] += s[i-1];
        }
    }

    int q; cin>>q;
    rep(i,q) {
        ll l, r;
        cin>>l>>r;
        int l_pos = lower_bound(all(x), l) - x.begin();
        int r_pos = lower_bound(all(x), r) - x.begin();
        if (r_pos == n) r_pos = n-1;
        else if (x[r_pos] != r && r_pos != 0) r_pos--;
        if(l_pos == 0) {
            if (r_pos == 0 && r < x[r_pos]) cout << 0 << endl;
            else cout << s[r_pos] << endl;
        } else {
            cout << s[r_pos] - s[l_pos-1] << endl;
        }
    }

    return 0;
}
