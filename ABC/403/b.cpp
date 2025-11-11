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
    string t, u;
    cin >> t >> u;
    rep(i, t.size()) {
        int index = 0;
        while(index < u.size()) {
            if (t[i + index] == u[index] || t[i + index] == '?') {
                index++;
            } else {
                break;
            }
            if (index == u.size()) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    
    return 0;
}
