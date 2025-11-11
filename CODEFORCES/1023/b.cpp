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
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        rep(i,n){
            cin >> a[i];
        }
        ll mx = *max_element(all(a));
        rep(i,n) {
            if (a[i] == mx) {
                a[i]--;
                break;
            }
        }
        mx = *max_element(all(a));
        ll mn = *min_element(all(a));
        if (mx  -mn > k){
            cout << "Jerry" << endl;
        } else {
            ll sum = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i];
            }
            if (sum % 2 == 0) {
                cout << "Tom" << endl;
            } else {
                cout << "Jerry" << endl;
            }
        }

    }

    return 0;
}
