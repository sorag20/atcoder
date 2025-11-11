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
    vector<string> s(n), t(n);
    rep(i, n) {
        cin >> s[i];
    }
    rep(i, n) {
        cin >> t[i];
    }
    ll ans = 0;
    rep(i, n) {
        rep(j, n) {
            if (s[i][j] != t[i][j]) {
                ans++;
            }
        }
    }


    rep(i, 4) {
        vector<string> s2(n, string(n, ' '));
        rep(j, n) {
            rep(k, n) {
                s2[k][n - j - 1] = s[j][k];
            }
        }

        ll cnt = i+1;
        rep(j, n) {
            rep(k, n) {
                if (s2[j][k] != t[j][k]) {
                    cnt++;
                }
            }
        }
        s = s2;
        ans = min(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
