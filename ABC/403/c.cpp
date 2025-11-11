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
    ll n, m, q;
    cin >> n >> m >> q;
    set<ll> st;
    vector<set<ll>> s(n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            s[x].insert(y);
        } else if (t == 2) {
            int x;
            cin >> x;
            x--;
            st.insert(x);
        } else if (t == 3) {
            int x, y;
            cin >> x >> y;
            x--;
            if (st.find(x) != st.end() || s[x].find(y) != s[x].end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
