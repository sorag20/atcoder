#include <bits/stdc++.h>
#include <set>
#include <queue>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#include <vector>
#define pb push_back
#define all(x) begin(x), end(x)
#define gall(x) begin(x), end(x), greater<>()
#define ll long long
#define rep(i,x) for(int i=0;i<x;i++)
#define P pair<int, int>
#define lP pair<ll, ll>
using namespace std;

int main()
{
    ll t;
    cin >> t;
    rep(i,t) {
        int n,k; cin >> n>>k;
        vector<string> a(n);
        vector<string> b(n/k);
        rep(j,n) {
            string s;
            cin >> s;
            a[j]=s;
        }
        rep(j,n/k) {
            string s= "";
            rep(l, n/k)
            {
                s += a[j*k][l*k];
            }
            b[j]=s;
        }
        rep(j,n/k) {
            rep(l,n/k) {
                cout << b[j][l];
            }
            cout << endl;
        }

    }

    return 0;
}
