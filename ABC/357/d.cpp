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
using mint = modint998244353;
int main()
{
    ll n;
    cin >> n;
    mint cnt = 1;
    {
        ll _n = n;
        while(_n) {
            cnt *= 10;
            _n /= 10;
        }
    }
    mint ans = (cnt.pow(n) - 1)/(cnt-1);
    ans *= n;
    cout << ans.val() << endl;
    return 0;
}
