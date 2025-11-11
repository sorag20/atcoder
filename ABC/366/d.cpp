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
    ll n;
    cin >> n;
    vector<vector<vector<ll>>> a(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1, 0)));
    vector<vector<vector<ll>>> t(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1, 0)));
    rep(i,n) {
        rep(j,n) {
            rep(k,n) {
                cin >> a[i][j][k];
            }
        }
    }

    // tはaの2次元累積和
    rep(i,n) {
        rep(j,n) {
            
        }
    }
    rep(i,n) {
        rep(j,n) {
            rep(k,n) {
                cout << t[i][j][k];
            }
            cout<<endl;
        }
    }
    ll q;
    vector<vector<ll>> query(q, vector<ll>(6, 0));
    rep(i,q) {
        rep(j,6) {
            cin >> query[i][j];
        }
    }
    rep(i, q)
    {
        ll x1 = query[i][0];
        ll y1 = query[i][1];
        ll z1 = query[i][2];
        ll x2 = query[i][3];
        ll y2 = query[i][4];
        ll z2 = query[i][5];
        cout << t[x2][y2][z2] - t[x1][y2][z2] - t[x2][y1][z2] - t[x2][y2][z1] + t[x1][y1][z2] + t[x1][y2][z1] + t[x2][y1][z1] - t[x1][y1][z1] << endl;
    }

    return 0;
}
