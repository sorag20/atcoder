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
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        ll ans = 1;
        int pre = -1;
        rep(i,n) {
            cin >> a[i];
            if (pre == -1) {
                pre = a[i];
            } else {
                if (a[i] > pre + 1) {
                    ans ++;
                    pre = a[i];
                } 
            }
        }

        cout << ans << endl;
    }// Output -1 after all test cases


    return 0;
}
