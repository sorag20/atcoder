const int m=1000000007;

ll func(ll x,ll y,ll m){
    ll res = 1,p = x;
    for(int i=0;i<=65;i++){
        if(y>>i&1) res = (res*p)%m;
        p = (p*p)%m;
    }
    return res;
}
