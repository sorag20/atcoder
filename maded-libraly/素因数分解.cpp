// kを素因数分解
// 計算量は、O(√k)
vc<lP> a;
for (ll p = 2; p * p <= k; ++p) {
    if (k % p != 0) continue;
    ll cnt = 0;
    while (k % p == 0) { k /= p; ++cnt; }
    a.emplace_back(p, cnt);
}
if (k > 1) a.emplace_back(k, 1);