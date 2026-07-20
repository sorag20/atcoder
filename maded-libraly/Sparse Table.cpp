struct SparseTable {
  int N, K;
  vc<char> log_table;
  vc<vc<int>> table;

  SparseTable(const vc<int>& A) {
    N = A.size();
    K = 0;
    while (1 << (K + 1) <= N) ++K;

    table.resize(K + 1);
    table[0] = A;
    for (int k = 0; k < K; ++k) {
      int m = N - (1 << (k + 1)) + 1;
      table[k + 1].resize(m);
      for (int i = 0; i < m; ++i) {
        table[k + 1][i] = min(table[k][i], table[k][i + (1 << k)]);
      }
    }

    log_table.resize(N + 1);
    for (int k = 0; k <= K; ++k) {
      int s = 1 << k, t = min((1 << (k + 1)) - 1, N);
      for (int n = s; n <= t; ++n) {
        log_table[n] = k;
      }
    }
  }

  // min of half interval [L,R)
  int query(int L, int R) {
    int k = log_table[R - L];
    return min(table[k][L], table[k][R - (1 << k)]);
  }
};