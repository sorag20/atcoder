#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
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
    ll n,k;
    cin >> n>>k;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll cnt = 0;
    sort(all(a));
    bool f = 0;
    rep(i, n)
    {
        cnt += a[i];
        if (k<=0) {
            if (cnt<k) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
        cout << "Yes" << endl;
        rep(i,n) {
            cout << a[i] << ' ';
        }

        return 0;
}
