struct frac {
  ll a, b;
  frac(ll _a=0, ll _b=1): a(_a), b(_b) {
    if (b == 0) { a = 1; return;}
    if (b < 0) a = -a, b = -b;
    ll g = gcd(abs(a),abs(b));
    a /= g; b /= g;
  }
  bool operator<(const frac& x) const {
    return a*x.b < x.a*b;
  }
  bool operator==(const frac& x) const {
    return a == x.a && b == x.b;
  }
};