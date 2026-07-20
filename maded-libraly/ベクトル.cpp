// Vector
// https://youtu.be/UWbGRhF3Ozw?t=9564
struct V {
  ll x, y;
  V(ll x=0, ll y=0): x(x), y(y) {}
  V& operator+=(const V& v) { x += v.x; y += v.y; return *this;}
  V operator+(const V& v) const { return V(*this) += v;}
  V& operator-=(const V& v) { x -= v.x; y -= v.y; return *this;}
  V operator-(const V& v) const { return V(*this) -= v;}
  V& operator*=(ll s) { x *= s; y *= s; return *this;}
  V operator*(ll s) const { return V(*this) *= s;}
  // 内積
  ll dot(const V& v) const { return x*v.x + y*v.y;}
  // 外積(外積が0 = 平行か、少なくとも一方がゼロベクトル)
  ll cross(const V& v) const { return x*v.y - v.x*y;}
  ll norm2() const { return x*x + y*y;}
  V rotate90() const { return V(y, -x);}
};
istream& operator>>(istream& is, V& v) {
  is >> v.x >> v.y; return is;
}
ostream& operator<<(ostream& os, const V& v) {
  os<<"("<<v.x<<","<<v.y<<")"; return os;
}