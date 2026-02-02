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
    //freopen("input.txt", "r", stdin);

    string x;
    cin>>x;
    ll n = (ll)x.size();
    vector<ll> a(n);
    rep(i,n) {
        a[i]= x[i] - '0';
    }
    sort(all(a));
    ll index = -1;
    rep(i,n) {
        if (a[i] != 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << x << endl;
        return 0;
    }
    cout << a[index];
    rep(i,n) {
        if (i != index) {
            cout << a[i];
        }
    }
    

    return 0;
}
