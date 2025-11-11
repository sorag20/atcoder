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

struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n), f(n+1) {
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
};
int main()
{
    ll n;
    cin >> n;
    Sieve p(1e6);

    ll ans = 0;
    ll size = p.primes.size();
    rep(i, size) {
        ll a = p.primes[i];
        if (a*a*a*a*a > n) {
            break;
        }
        for (int j = i+1; j < size; j++) {
            ll b = p.primes[j];
            if (a*a*b*b*b > n) {
                break;
            }
            for (int k = j+1; k < size; k++) {
                ll c = p.primes[k];
                if (a*a*b*c*c > n) {
                    break;
                }
                ans++;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
