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
    ll t;
    cin >> t;
    while(t--) {
        ll k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        
        ll ans = 0;
        ll temp_1= 0, temp_2 = 0;
        ll cnt_1 = k, cnt_2 = k;
        if (cnt_1 >= a) {
            temp_1 += (cnt_1 - a) / x + 1;
            cnt_1 -= temp_1 * x;
            if (cnt_1 >= b) {
                temp_1 += (cnt_1 - b) / y + 1;
            }
        }
        if (cnt_2 >= b) {
            temp_2 += (cnt_2 - b) / y + 1;
            cnt_2 -= temp_2 * y;
            if (cnt_2 >= a) {
                temp_2 += (cnt_2 - a) / x + 1;
            }
        }

        ans = max(temp_1, temp_2);
        cout << max(0LL, ans) << endl;
    }

    return 0;
}
