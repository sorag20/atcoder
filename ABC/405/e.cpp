#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
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
using mint = modint998244353;
struct modinv {
    int n; vector<mint> d;
    modinv(): n(2), d({0,1}) {}
    mint operator()(int i) {
      while (n <= i) d.push_back(-d[mint::mod()%n]*(mint::mod()/n)), ++n;
      return d[i];
    }
    mint operator[](int i) const { return d[i];}
  } invs;
  struct modfact {
    int n; vector<mint> d;
    modfact(): n(2), d({1,1}) {}
    mint operator()(int i) {
      while (n <= i) d.push_back(d.back()*n), ++n;
      return d[i];
    }
    mint operator[](int i) const { return d[i];}
  } facts;
  struct modfactinv {
    int n; vector<mint> d;
    modfactinv(): n(2), d({1,1}) {}
    mint operator()(int i) {
      while (n <= i) d.push_back(d.back()*invs(n)), ++n;
      return d[i];
    }
    mint operator[](int i) const { return d[i];}
  } ifacts;
  mint comb(int n, int k) {
    if (n < k || k < 0) return 0;
    return facts(n)*ifacts(k)*ifacts(n-k);
  }

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    mint ans = 0;
    rep(i,b+1) {
        mint now = comb(a-1+i, i);
        now *= comb(b-i + d + c, c );
        ans += now; 
    }
    cout << ans.val() << endl;

    return 0;
}
