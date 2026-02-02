#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <regex>
#include <math.h>
#include <random>
#include <algorithm>
#define pb push_back
#define eb emplace_back
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

    ll n,q;
    cin >> n >> q;
    vector<multiset<ll>> box(n+ 1);
    vector<set<ll>> card(2e5+5);
    
    rep(i,q) {
        ll t;
        cin>>t;
        if (t ==1) {
            ll i, j; cin>>i>>j;
            box[j].insert(i);
            card[i].insert(j);
        } else if (t == 2) {
            ll i; cin>>i;
            for (auto c:box[i]) {
                cout << c << " ";
            }
            cout << endl;
        } else {
            ll i; cin>>i;
            for (auto c:card[i]) {
                cout << c << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
