#include <bits/stdc++.h>
#include <atcoder/all>
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define ll long long
using namespace std;
using namespace atcoder;

using S = ll;
using F = ll;
const ll INF = 1LL << 60;

S op(S a, S b) { return max(a, b); }
S e() { return -INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> R(n+1);
    rep(i,m) {
        ll l, r, a;
        cin >> l >> r >> a;
        R[r].pb({l, a});
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n+1);
    seg.apply(0, 1, 0); // dp[0] = 0

    rep(r, n) {
        ll max_value = seg.prod(0, r+1);
        // dp[r+1] に max_value を反映（最大値更新）
        ll current = seg.prod(r+1, r+2);
        if (max_value > current) {
            seg.apply(r+1, r+2, max_value - current);
        }

        for (auto [l, a] : R[r]) {
            ll val = seg.prod(l, r+1) + a;
            current = seg.prod(r+1, r+2);
            if (val > current) {
                seg.apply(r+1, r+2, val - current);
            }
        }
    }

    cout << seg.prod(0, n+1) << endl;
    return 0;
}
