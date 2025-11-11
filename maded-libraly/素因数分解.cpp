vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll p = 2; p * p <= N; ++p) {
        if (N % p != 0) {
            continue;
        }

        int e = 0;
        while (N % p == 0) {
            ++e;
            N /= p;
        }
        res.emplace_back(p, e);
    }
    if (N != 1) {
        res.emplace_back(N, 1);
    }
    return res;
}
