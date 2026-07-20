// 部分木クエリによく使う。パスクエリやLCAにも使える
// 頂点に重みを加算、部分木の和
#include <bits/stdc++.h>
#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
using vc = vector<T>;

#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i)
#define len(x) int(x.size())

void solve() {
  int N, Q;
  cin >> N >> Q;
  vc<int> A(N);
  FOR(i, 0, N) cin >> A[i];

  // adjacency list
  vc<vc<int>> G(N);
  FOR(v, 1, N) {
    int p;
    cin >> p;
    G[p].emplace_back(v);
    G[v].emplace_back(p);
  }

  // Euler Tour
  vc<int> in(N), out(N), tour;
  {
    auto dfs = [&](auto& dfs, int v, int par) -> void {
      in[v] = len(tour);
      tour.emplace_back(v);
      for (int w : G[v]) {
        if (w != par) dfs(dfs, w, v);
      }
      out[v] = len(tour);
    };
    dfs(dfs, 0, -1);
  }

  // Fenwick Tree to process range queries
  fenwick_tree<ll> fw(N);
  FOR(i, 0, N) fw.add(i, A[tour[i]]);

  FOR(q, 0, Q) {
    int t;
    cin >> t;
    if (t == 0) {
      int v, x;
      cin >> v >> x;
      fw.add(in[v], x);
    }
    if (t == 1) {
      int v;
      cin >> v;
      ll ans = fw.sum(in[v], out[v]);
      cout << ans << "\n";
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
}