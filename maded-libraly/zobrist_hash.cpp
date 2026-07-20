struct ZobristHash {
    unordered_map<ll, uint64_t> mp;
    mt19937_64 rng;
    ZobristHash() :rng(chrono::steady_clock::now().time_since_epoch().count()) {}

    uint64_t operator()(ll x) {
        auto it = mp.find(x);
        if (it != mp.end()) return it->second;
        return mp[x] = rng();
    }

    void add(uint64_t &h, ll x) {
        h ^= (*this)(x);
    }

    void erase(uint64_t &h, ll x) {
        h ^= (*this)(x);
    }
};


ZobristHash zh;
vector<uint64_t> hashA(n + 1), hashB(n + 1);
set<ll> sa, sb;

rep(i,n) {
    hashA[i+1] = hashA[i];
    if (sa.insert(a[i]).second)
        zh.add(hashA[i+1], a[i]);
}

rep(i,n) {
    hashB[i+1] = hashB[i];
    if (sb.insert(b[i]).second)
        zh.add(hashB[i+1], b[i]);
}