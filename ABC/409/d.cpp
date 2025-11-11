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
    ll t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int l = -1;
        rep(i, n - 1) {
            if (s[i] > s[i + 1]) {
                l = i;
                break;
            }
        }
        if (l != -1) {
            int r = n-1;
            for (int i = l + 1; i < n - 1; i++) {
                if (s[l] < s[i + 1]) {
                    r = i;
                    break;
                }
            }
            rotate(s.begin() + l, s.begin() + l + 1, s.begin() + r + 1);
            cout << s << endl;
        } else {
            cout << s << endl;
        }
    }

    return 0;
}
