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
    vector<string> s(n);
    rep(i,n) {
        cin >> s[i];
    }
    int ans = 110;
    rep(i, 1 << n)
    {
        int cnt = 0;
        vector<int> check(m);
        rep(j, n)
        {
            if (i>>j&1) {
                cnt++;
                rep(k,m) {
                    if (s[j][k] == 'o') {
                        check[k]++;
                    }
                }
            }
        }
        rep(k,m) {
            if (check[k] == 0) {
                break;
            }
            if (k == m - 1) {
                ans = min(ans, cnt);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
