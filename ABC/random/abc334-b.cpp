#include <bits/stdc++.h>
#include <atcoder/all>
#define pb push_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for(int i=0;i<x;i++)
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;

ll f(ll l, ll m){
    return l / m;
}

int main()
{
    ll a, m, l, r;
    cin>>a>>m>>l>>r;
    l -= a;
    r -= a;
    if (l<0) {
        ll x = (-l/m + 1)*m;
        l += x;
        r += x;
    }
    ll ans = f(r,m) - f(l-1,m);
    cout << ans << endl;

    return 0;
}
