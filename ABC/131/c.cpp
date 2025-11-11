#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <atcoder/all>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define P pair<int, int>
#define lP pair<ll, ll>
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;
using namespace atcoder;


int main()
{
  ll t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m), forward(m), backward(m);
    rep(i, n) {
      cin >> a[i];
    }
    rep(i,m) {
      cin >> b[i];
    }
    rep(i,m) {
      int j = i;
      while(j < m && a[i] < b[i]) j++;
      forward[i] = i;
      i++;
    }
    for (int i = m - 1; i >= 0; i--) {
      while(i >= 0 && a[i] > b[i]) i--;
      backward[i] = i;
      i--;
    }
    const int INF = 1e9;
    ll ans = INF;
    for (int i = 1; i < m - 1; i++) {
      if (forward[i- 1] <  backward[i + 1]) {
        ans = min(ans, b[i]);
      }
    }
    if (ans == INF) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
    
  
  }

    return 0;
} 
