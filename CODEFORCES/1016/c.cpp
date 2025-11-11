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
            if (y == 1) {
                cout << "NO" << endl;
                continue;
            } else {
                string s;
                rep(j, y) {
                    s += '1';
                }
                int t = stoi(s);
                bool ok = false;
                for (ll j = 2; j*j <= t; j++) {
                    if (t % j == 0) {
                        cout << "NO" << endl;
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    cout << "YES" << endl;
                }
            }
        } else {
            if (y == 1) {
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
            } else {
                cout << "NO" << endl;
                continue;
            }
        }

    }
    return 0;
}
