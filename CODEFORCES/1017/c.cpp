#include <bits/stdc++.h>
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

int main()
{
    ll n;
    cin >> n;
    rep(i,n) {
        int t;
        cin >> t;
        vector<int> a(2*t);
        vector<vector<int>> z(t, vector<int>(t));
        vector<int> s;
        rep(j, t) {
            rep(k, t) {
                if (j == 0) {
                    cin>> z[j][k];
                    s.push_back(z[j][k]);
                } else {
                    if (k == t-1) {
                        cin >> z[j][k];
                        s.push_back(z[j][k]);
                    } else {
                        cin >> z[j][k];
                    }
                }
            }
        }
        int missing = -1;
        for (int j = 1; j <= 2*t; j++) {
            if (find(s.begin(), s.end(), j) == s.end()) {
                missing = j;
                break;
            }
        }
        cout << missing << " ";
        for (auto it = s.begin(); it != s.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    
    return 0;
}
