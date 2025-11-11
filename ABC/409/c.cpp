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
    ll n, l;
    cin >> n >> l;
    vector<ll> d(n-1);
    vector<ll> m(l + 1, 0);
    int temp = 0;
    m[0] = 1;
    rep(i, n-1) {
        cin >> d[i];
        temp += d[i];
        m[temp % l]++;
        temp %= l;
    }
    if (l % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i <= l -1; i++) {
        ans += m[i] * m[(i + l / 3) % l] * m[(i + 2 * l / 3) % l];
    }
    ans /= 3;
    cout << ans << endl;

    return 0;
}
