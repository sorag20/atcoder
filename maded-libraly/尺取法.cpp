    // rは、区間の右端の次([l,r)として持つ）
    ll r = 0;
    rep(l,sn) {
        while(r < sn) {
            if (r-l >= 1 && s[r] == s[r-1]) break;
            r++;
        }
        ans += r-l;
    }