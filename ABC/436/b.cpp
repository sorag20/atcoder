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
using mint = modint;

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    mint::set_mod(n);
    vector<vector<ll>> a(n,vector<ll> (n, -1));
    a[0][(n-1)/2] = 1;
    pair<ll,ll> before = {0,(n-1)/2};
    ll k = 1;
    rep(i,n)rep(j,n) {
        if (i == 0 && j == (n-1)/2) continue;
        mint nx = (mint)before.first-(mint)1;
        mint nx_2 = (mint)before.first+(mint)1;
        mint ny = (mint)before.second+(mint)1;
        if (a[nx.val()][ny.val()] == -1) {
            a[nx.val()][ny.val()] = k+1;
            before = {nx.val(), ny.val()};
            k++;
        } else {
            a[nx_2.val()][before.second] = k+1;
            before = {nx_2.val(), before.second};
            k++;
        }
    }

    rep(i,n){
        rep(j,n) {
        cout <<a[i][j] << ' ';
        }
        cout <<endl;
    }

    return 0;
}
