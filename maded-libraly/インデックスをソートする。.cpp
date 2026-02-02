  vector<int> is(n);
  rep(i,n) is[i] = i;
  sort(is.begin(), is.end(), [&](int i, int j) {
    return a[i] > a[j];
  });
