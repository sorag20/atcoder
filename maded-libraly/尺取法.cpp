    vector<ll> d(n);// 左端が決まったとき、右端はどこまで行けるか
    auto check = [&](ll l, ll r) -> bool {
        if (r >= n) return false;
        if (l == 0) {
            if (s[r] <= k) return true;
        } else {
            if (s[r] - s[l-1] <= k) return true;
        }
        return false;
    };
    ll res = 0;
    rep(left, n) {
        if (left == 0) d[left] = 0;
        else d[left] = d[left-1];

        while (d[left] < n && check(left, d[left] + 1)) {
            d[left]++;
        }

        // 区間 [left, right-1] が条件を満たす
        res += d[left] - left +1;
    }
