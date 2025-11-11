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
        ll n;
        cin >> n;
        vector<ll> a(n);
        rep(i, n) cin >> a[i];
        ll mn = *min_element(all(a));
        ll mx = *max_element(all(a));
        if (mn == mx){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            rep(i, n){
                if (a[i] == mx){
                    cout << 2 << " ";
                } else {
                    cout << 1 << " ";
                }
            }
            cout << endl;
        }

    }



    return 0;
}
