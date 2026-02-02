#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define eb emplace_back
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
    //freopen("input.txt", "r", stdin);

    ll const M = 26;
    ll k;
    cin >> k;
    vector<ll> c(M);
    rep(i,M) cin>>c[i];

    vector<mint> dp(k+1);
    dp[0] = 1;

    rep(i,M) {
        vector<mint> old(k+1);
        swap(old, dp);
        rep(j, k+1) {
            rep(a, c[i] + 1) {
                int nj = j+a;
                if (nj > k) break;
                dp[nj] += old[j] * comb(nj,a);
            }
        }
    }

    mint ans;
    rep(i,k) {
        ans += dp[i+1];
    }
    cout << ans.val() << endl;

    return 0;
}
