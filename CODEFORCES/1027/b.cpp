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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int o_cnt = 0, one_cnt = 0;
        rep(i,n) {
            if (s[i] == '0') {
                o_cnt++;
            } else {
                one_cnt++;
            }
        }
        o_cnt /= 2; // Count pairs of '0's
        one_cnt /= 2; // Count pairs of '1's
        if (k <= o_cnt + one_cnt  && k >= max(o_cnt , one_cnt) - min(o_cnt , one_cnt)&&  k%2 == (o_cnt + one_cnt) % 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }// Output -1 after all test cases


    return 0;
}
