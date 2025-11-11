#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
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
    ll n,m;
    cin >> n>>m;
    vector<int> ab(n+m);
    vector<int> a(n);
    vector<int> b(m);


    rep(i, n)
    {
        int x;
        cin >> x;
        a[i] = x;
        ab[i] = x;
    }
        rep(i, n)
    {
        int y;
        cin >> y;
        b[i] = y;
        ab[i] = y;
    }
    sort(all(ab));
    bool f = false;
    rep(i, n + m - 1)
    {
        if (count(all(a),ab[i]) > 0) {
            if (count(all(a),ab[i+1]) > 0) {
                cout << "Yes" << endl;
                f = true;
                break;
            }
        }
    }
    if (!f){
        cout << "No" << endl;
    }

    return 0;
}
