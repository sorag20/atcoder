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
    string n;
    cin >> n;
    int n_size = n.size();
    ll ans = 0;
    ll cnt = 0;
    rep(i,n_size-1) {
        if (n[i] == 'i' && n[i+1] == 'o') {
            cnt++;
        }
    }
    ans = n_size - 2*cnt;
    cout << ans << endl;
    return 0;
}
