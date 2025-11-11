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
void chmin(int& x, int y) { x = min(x,y);}
int main()
{
  int n;
  string s;
  cin >> n >> s;

  vector dp(s.size(), vector<int>(2,1));
  rep(i,s.size()) dp[i][s[i]-'0'] = 0;

  const int INF = 1001001001;
  while (dp.size() > 1) {
    vector old(dp.size()/3, vector<int>(2,INF));
    swap(dp,old);
    for (int l = 0; l < old.size(); l += 3) {
      rep(s,8) {
        int cost = 0;
        rep(i,3) cost += old[l+i][s>>i&1];
        int x = __builtin_popcount(s)>=2 ? 1 : 0;
        chmin(dp[l/3][x], cost);
      }
    }
  }

    int ans = max(dp[0][0], dp[0][1]);
    cout << ans << endl;
    
    return 0;
}
