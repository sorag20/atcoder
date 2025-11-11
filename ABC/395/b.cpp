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
    string S;
    rep(i,n) {
        S += '#';
    }   
    vector<string> s(n, S);

    rep(i,n) {
        for (int j = i; j < n -i; j++) {
            for (int k = i; k < n -i; k++) {
                    if (i %2 == 0) {
                        s[j][k] = '#';
                    } else {
                        s[j][k] = '.';
                    }
            }
        }
    }
    rep(i,n) {
        cout << s[i] << endl;
    }
    return 0;
}
