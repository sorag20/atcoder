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
    ll n,m;
    cin >> n>>m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    rep(i,n) {
        rep(j,m){
            int x;
            cin >> x;
            a[j] -= x;
        }
    }
    bool f = true;
    rep(i,m){
        if (a[i]>0)
            f = false;
    }
    if (f) {
        cout << "Yes" << endl;
    } else {
        cout<<"No"
    }

        return 0;
}
