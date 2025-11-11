#include <bits/stdc++.h>
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
int main()
{
    int t;
    cin >> t;
    rep(i,t) {
        ll x, y;
        cin >> x >> y;
        if (x == 1) {
            cout << "NO" << endl;
            continue;
        }
        bool ok = false;
        for (ll j = 2; j*j <= x; j++) {
            if (x % j == 0) {
                cout << "NO" << endl;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "YES" << endl;
        }
    }

    return 0;
}
