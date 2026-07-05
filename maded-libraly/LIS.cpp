    const ll INF = 1e18;
    vector<ll> a(n), dp(n, INF);
    rep(i,n) cin >> a[i];
    ll ans = 0;

    rep(i,n) {
        int pos = lower_bound(all(dp), a[i]) - dp.begin();
        dp[pos] = a[i];
    }

    rep(i,n) {
        if (dp[i] != INF) ans++;
    }
    cout << ans << endl;