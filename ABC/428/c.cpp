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

int main()
{
    freopen("input.txt", "r", stdin);

    ll q;
    cin >> q;
    ll cnt = 0;
    bool f = true;
    string s;
    ll index = -5;
    rep(i,q) {
        int t;
        cin>> t;
        if (t == 1) {
            char c;
            cin >> c;
            if (c == '(') {
                cnt++;
                s+= '(';
            } else {
                cnt--;
                s+=')';
                if (cnt < 0 && f) {
                    f = false;
                    index = i;
                }
            }
        } else {
            int n =s.size();
            char C = s[n-1];
             s.pop_back();
            if (C == '(') cnt--;
            else cnt++;
            if (cnt == 0 && n-1 == index)  {
                f = true;
                index = -5;
            }
        }
        if (cnt == 0 && f) {
            cout <<"Yes" << endl;
        } else {
            cout <<"No" << endl;
        }
    }

    return 0;
}
