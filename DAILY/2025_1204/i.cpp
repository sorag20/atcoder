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


struct Seg {
    int s, d;
    Seg(int s = 0, int d = 0): s(s), d(d) {}
};

Seg op(Seg a, Seg b) {
    return Seg(a.s+b.s, min(a.d, a.s+b.d));
}
Seg e()
 {
    return Seg(0,0);
 }

//　カッコ列をsegtreeで判定
int main()
{
    //freopen("input.txt", "r", stdin);

    int n,q;
    cin >> n >> q;
    string s;
    cin>>s;

    segtree<Seg,op, e> t(n);
    auto f = [&](char c) {
        return c == '(' ? Seg(1,0) : Seg(-1, -1);
    };
    rep(i,n) {
        t.set(i, f(s[i]));
    }
    rep(i,q) {
        int type, l, r;
        cin >> type>> l>> r;
        l--;
        if (type == 1) {
            r--;
            swap(s[l], s[r]);
            t.set(l, f(s[l]));
            t.set(r, f(s[r]));
        } else {
            Seg res = t.prod(l,r);
            if (res.s == 0 && res.d == 0) cout << "Yes" << endl;
            else cout <<"No" << endl;
        }
    }


    return 0;
}
