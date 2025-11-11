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
    rep(i,t) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        set<string> st;

        ll ans = 0;
        auto f = [&](auto f, string s) {
            if (st.count(s)) return;
            int cnt_0 = 0;
            int cnt_1 = 0;
            st.insert(s);
            ans++;
            string t;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    cnt_0++;
                    t += '1';
                } else {
                    cnt_1++;
                    t += '0';
                }
                if (cnt_0 == cnt_1) {
                    f(f, t+ s.substr(i+1));
                }
            }
        };
        f(f, s);
        cout << ans << endl;
    }
    
    return 0;
}
