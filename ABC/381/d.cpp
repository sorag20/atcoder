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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    rep(i, 2) {
        set<int> s;
        int r = i;
        for (int l = i; l + 1 < n; l+=2) {
            while  (r + 1 < n) {
                if (a[r] != a[r+1]) break;
                if (s.count(a[r])) break;
                s.insert(a[r]);
                r+= 2;
            }
            ans = max(ans, r - l);
            if (l == r) r+= 2;
            else s.erase(a[l]);
        }
    }
    cout << ans << endl;
    
    return 0;
}
