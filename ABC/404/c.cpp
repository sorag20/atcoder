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
    ll n, m;
    cin >> n >> m;
    dsu uf(n);
    int cnt = 0;
    bool flag = true;
    map<ll, ll> mp;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if (uf.same(a, b)) {
            if (a != b) {
                if (mp[a] ==1 && mp[b] == 1) {
                    cnt++;
                } else {
                    flag = false;
                }
            } else {
                flag = false;
            }
        }
        if (a == b) {
            flag = false;
        }
        mp[a]++;
        mp[b]++;
        uf.merge(a, b);
    }
    rep(i, n) {
        if (mp[i] != 2) {
            flag = false;
        }
    }
    int groups = uf.groups().size();
    if (flag && groups == 1 && cnt == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
