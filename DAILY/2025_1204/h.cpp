#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for(int i=0;i<x;i++)
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;
using namespace atcoder;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const ll M = 1e6;
vector<ll> f(vector<ll> x) {
    int n = x.size();
    rep(i,n) x[i] += M*2;
    ll s= 0;
    rep(i,n) s += x[i];
    vector<ll> res(M*4+1);
    res[0] = s;

    int k = 0;
    sort(all(x));
    for (int i = 1;i <= M*4 ; i++) {
        while(k <n && x[k] < i) k++;
        s-= n- k*2;
        res[i] = s;
    }

    return res;
}


int main()
{
    //freopen("input.txt", "r", stdin);

    ll n,d;
    cin >> n >>d;
    vector<ll> x(n), y(n);
    rep(i,n){
        cin>>x[i]>>y[i];
    }
    vector<ll> a = f(x);
    vector<ll> b = f(y);
    sort(all(a));
    sort(all(b));

    ll ans = 0;
    int j = b.size()- 1;
    rep(i,a.size()) {
        while(j >= 0 && a[i] + b[j] > d) j--;
        ans += j+1;
    }
    cout << ans << endl;

    return 0;
}
