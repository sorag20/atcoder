vl ds;
set<ll> st;
for (ll i = 1;i*i <= n;i++) {
    if (n%i == 0){
        st.insert(i);
        st.insert(n/i);
    }
}
ds = vl(all(st));