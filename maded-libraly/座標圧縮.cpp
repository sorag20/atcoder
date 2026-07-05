vl ys;
rep(i,n) {
  ys.pb(ab[i].second);
}
sort(all(ys));
vc_unique(ys);
auto idx = [&](ll v) ->ll { 
  return lower_bound(all(ys), v) - ys.begin();
};