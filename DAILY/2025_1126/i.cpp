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

using mint = modint998244353;

struct F {
    mint a, b;
    F(mint a= 1, mint b = 0): a(a), b(b) {}
};

mint op(mint a, mint b) {return a+b;}
mint e() {return 0;}
mint mapping (F f, mint x) {
    return f.a*x + f.b;
}
F composition (F g, F f) {
    return F(f.a * g.a, g.b+ g.a* f.b);
}
F id() {return F(1,0);}

int main()
{
    //freopen("input.txt", "r", stdin);

    int n,m;
    cin >> n >> m;
    vector<mint> a;
    rep(i,n) {
        int _a;
        cin>> _a;
        a.pb(_a);
    }

    lazy_segtree<mint, op, e, F, mapping, composition, id> t(a);
    rep(qi,m) {
        int l, r, x;
        cin>> l >> r>> x;
        l--;
        mint p = mint(1)/ (r-l), q = mint(1) - p;

        t.apply(l, r, F(q, p*x));
    }

    rep(i,n) {
        mint ans = t.get(i);
        cout << ans.val() << ' ';
    }
    cout << endl;
    return 0;
}
