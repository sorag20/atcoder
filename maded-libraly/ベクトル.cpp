// Geometry
const ld eps = 1e-9;
bool equal(ld a, ld b) { return abs(a-b) < eps;}

// Vector
// https://youtu.be/UWbGRhF3Ozw?t=9564
struct V {
  ld x, y;
  V(ld x=0, ld y=0): x(x), y(y) {}
  V& operator+=(const V& v) { x += v.x; y += v.y; return *this;}
  V operator+(const V& v) const { return V(*this) += v;}
  V& operator-=(const V& v) { x -= v.x; y -= v.y; return *this;}
  V operator-(const V& v) const { return V(*this) -= v;}
  V& operator*=(ld s) { x *= s; y *= s; return *this;}
  V operator*(ld s) const { return V(*this) *= s;}
  V& operator/=(ld s) { x /= s; y /= s; return *this;}
  V operator/(ld s) const { return V(*this) /= s;}
  ld dot(const V& v) const { return x*v.x + y*v.y;}
  ld cross(const V& v) const { return x*v.y - v.x*y;}
  ld norm2() const { return x*x + y*y;}
  ld norm() const { return sqrt(norm2());}
  V normalize() const { return *this/norm();}
  V rotate90() const { return V(y, -x);}
  int ort() const { // どの象限にあるか
    if (abs(x) < eps && abs(y) < eps) return 0;
    if (y > 0) return x>0 ? 1 : 2;
    else return x>0 ? 4 : 3;
  }
  bool operator<(const V& v) const {
    int o = ort(), vo = v.ort();
    if (o != vo) return o < vo;
    return cross(v) > 0;
  }
};
istream& operator>>(istream& is, V& v) {
  is >> v.x >> v.y; return is;
}
ostream& operator<<(ostream& os, const V& v) {
  os<<"("<<v.x<<","<<v.y<<")"; return os;
}

struct Line {
  V s, t;
  Line(V s=V(0,0), V t=V(0,0)):s(s),t(t){}
  V dir() const { return t-s;}
  V normalize() const { return dir().normalize();}
  ld norm() const { return dir().norm();}
  /* +1: s-t,s-p : ccw
   * -1: s-t,s-p : cw
   * +2: t-s-p
   * -2: s-t-p
   *  0: s-p-t */
  int ccw(const V& p) const {
    if (dir().cross(p-s) > eps) return +1;
    if (dir().cross(p-s) < -eps) return -1;
    if (dir().dot(p-s) < -eps) return +2;
    if (dir().dot(t-p) < -eps) return -2;
    return 0;
  }
  bool touch(const Line& l) const {
    int a = ccw(l.s)*ccw(l.t), b = l.ccw(s)*l.ccw(t);
    return !a || !b || (a == -1 && b == -1);
  }

  V divpoint(ld p) const {
    return s*(1-p) + t*p;
  }
  // 点pから、線分stまでの最短距離
  ld distSP(V p) const {
    if ((p-s).dot(t-s) < eps) return (s-p).norm();
    if ((p-t).dot(s-t) < eps) return (t-p).norm();
    return abs((s-p).cross(t-p))/(t-s).norm();
  }
};