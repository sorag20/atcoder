#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <queue>
#include <stack>
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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
#define TU tuple<ll, ll, ll>

int main()
{
    //freopen("input.txt", "r", stdin);

    ll T;
    cin>>T;
    while(T--) {
        ll n,h;
        cin>> n>>h;
        vector<TU> _t;
        ll now_highest = h;
        ll now_lowest = h;
        ll now_time = 0;
        bool no = false;
        rep(i,n) {
            ll t,l, u;
            cin>> t>>l>>u;
            _t.emplace_back(t, l, u);
        }
        rep(i,n) {
            auto [t,l,u] = _t[i];
            ll diff_t = t - now_time;
            ll possible_highest = now_highest + diff_t;
            ll possible_lowest = max((ll)0, now_lowest - diff_t);
            if (l > possible_highest || possible_lowest > u) {
                cout << "No" <<endl;
                no = true;
                break;
            }
            now_time = t;
            now_highest = min(u, possible_highest);
            now_lowest = max(l, possible_lowest);
        }

        if (!no) {
            cout << "Yes" << endl;
        }

    }


    return 0;
}
