vector<int> l(q), r(q);
rep(i,q) cin >> l[i] >> r[i];
rep(i,q) l[i]--, r[i]--;
const int D = max(1,int(n/sqrt(q)));
vector<int> qis(q);
iota(qis.begin(),qis.end(),0);
sort(qis.begin(),qis.end(),[&](int i, int j) {
    int di = r[i]/D, dj = r[j]/D;
    if (di != dj) return di < dj;
    return l[i] < l[j];
});

vector<ll> ans(q);
int nl = 0, nr = -1;
// unordered_mapにしないと、TLEになった。
unordered_map<ll,ll> mp;
ll now = 0;
auto add = [&](int i) {
    if (!mp.count(p[i]) || mp[p[i]] == 0) now++;
    mp[p[i]]++;
};
auto del = [&](int i) { 
    mp[p[i]]--;
    if (mp[p[i]] == 0) now--;
};
for (int qi : qis) {
    while (nl < l[qi]) del(nl), nl++;
    while (nl > l[qi]) nl--, add(nl);
    while (nr < r[qi]) nr++, add(nr);
    while (nr > r[qi]) del(nr), nr--;
    ans[qi] = now;
}

rep(i,q) cout << ans[i] << endl;
