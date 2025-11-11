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

int main()
{
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    if ((sx+sy)%2 ==1)
        sx--;
    if ((tx+ty)%2 ==1)
        tx--;
    ll x = abs(tx-sx);
    ll y = abs(ty - sy);
    ll ans = 0;
    if (x <y)
        ans = y;
    else ans = (x+y)/2;
    cout << ans << endl;
    return 0;
}
