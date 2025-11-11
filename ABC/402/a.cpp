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
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        rep(i,n) {
            cin >> a[i];
        }
        rep(i,m) {
            cin >>b[i];
        }
        ll index = 0;
        bool flag = false;
        rep(i,n) {
            if (a[i] >= b[index]) {
                index++;
            }
            if (index == m -1) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << 0 << endl;
        } else {
            ll longest_distance = 0;
            ll longest_index = 0;
            ll pre_index = 0;
            ll index = 0;
            ll cnt = 0;
            rep(i,n) {
                if (a[i] >= b[index]) {
                    index++;
                    if (cnt > longest_distance) {
                        longest_index = pre_index;
                    }
                    longest_distance = max(longest_distance, cnt);
                    cnt = 0;
                    pre_index = i;
                } else {
                    cnt++;
                }
            }
        }
        bool flag = false;
        rep(i,n) {
            if (i + 1 == longest_index) {
                continue;
            }
            if (a[i] >= b[index]) {
                index++;
            }
            if (index == m -1) {
                flag = true;
                break;
            }
        }
    }
    
    return 0;
}