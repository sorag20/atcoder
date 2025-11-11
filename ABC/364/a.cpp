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
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) {
        cin >> s[i];
    }
    bool f = false;
    rep(i, n)
    {
        if (s[i] == "sweet")
        {
            if (f && i != n-1) {
                cout << "No" << endl;
                return 0;
            }
            f = true;
        } else {
            f = false;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
