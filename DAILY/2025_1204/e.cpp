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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin>>s[i];
    vector<string> t = s;
    rep(i,n){
        rep(j,n) {
            ll temp_1 = min(i+1,j+1), temp_2 = min(n-i, n-j);
            ll current_circle = min(temp_1,temp_2);
            if (current_circle%4 == 0) {
                t[i][j] = s[i][j];
            } else if(current_circle%4 == 1) {
                t[j][n-1-i] = s[i][j];
            } else if(current_circle%4 == 2) {
                t[n-1-i][n-1-j] = s[i][j];
            } else {
                t[n-1-j][i] = s[i][j];
            }
        }
    }
    rep(i,n){
        rep(j,n) {
        cout << t[i][j];
        }
        printf("\n");
    }

    return 0;
}
