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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);

    ll q;
    cin >> q;
    deque<lP> v; // {c, x}
    rep(i,q){
        int t;
        cin >> t;
        if (t == 1) {
            ll c, x;
            cin >> c >> x;
            v.pb({c, x});
        } else {
            ll k;
            cin >> k;
            ll sum = 0;
            while(v.size()) {
                lP p = v.front();
                v.pop_front();
                if (p.first >= k) {
                    sum += k * p.second;
                    cout << sum << endl;
                    p.first -= k;
                    if (p.first > 0) {
                        v.push_front(p);
                    }
                    break;
                } else {
                    k -= p.first;
                    sum += p.first * p.second;
                }
            }
        }
    }

    return 0;
}
