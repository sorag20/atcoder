// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  ll n;
  vector<ll> f, primes;
  Sieve(ll n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  // xが素数かどうかを判定する。
  bool isPrime(ll x) { return f[x] == x;}

  // 篩を用いて、xを素因数分解する。
  // リストを返す。
  // 計算量はO(素因数の個数)
  vector<ll> factorList(ll x) {
    vector<ll> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  // 篩を用いて、xを素因数分解する。
  // ランレングス圧縮版
  // 計算量はO(素因数の個数)
  vector<lP> factor(ll x) {
    vector<ll> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<lP> res(1, P(fl[0], 0));
    for (ll p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};
