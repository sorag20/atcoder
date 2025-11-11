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

int min(int a, int b, int c, int d) {
    return min(a, min(b, min(c, d)));
}
int main()
{
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<string> ans;
    ans = s;

    rep(i,n)rep(j,n) {
        int ni = i;
        int nj = j;
        int k = min(ni+1,nj+1, n-ni, n-nj);
        rep(l,k%4) {
            swap(ni, nj);
            nj = n - nj - 1;
        }
        ans[ni][nj] = s[i][j];
    }
    rep(i,n) cout << ans[i] << endl;

    return 0;
}
