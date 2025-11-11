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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int temp = 0;
    int ans = 0;
    while(temp <= 100) {
        int cnt = 0;
        rep(i,n) {
            if (a[i] >= temp) {
                cnt++;
            }
        }
        if (cnt >= temp) {
            ans = max(ans, temp);
        }
        temp++;
    }
    cout << ans << endl;

    return 0;
}
