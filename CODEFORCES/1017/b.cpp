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
    ll n;
    cin >> n;
    rep(i,n) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        int cnt = n-m;
        while (cnt > 0) {
            if (abs(l) == abs(r)) {
                if (r > 0) {
                    r--;
                } else {
                    r++;
                }
            } else if (abs(l) > abs(r)) {
                if (l > 0) {
                    l--;
                } else {
                    l++;
                }
            } else {
                if (r > 0) {
                    r--;
                } else {
                    r++;
                }
            }
            cnt--;
        }
        cout << l << " " << r << endl;
    }
    return 0;
}
