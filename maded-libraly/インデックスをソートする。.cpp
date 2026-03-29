  vl index(n);
  rep(i,n) index[i] = i;
  sort(index.begin(), index.end(), [&](int i, int j) {
      return a[i] < a[j];
  });
