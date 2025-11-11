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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<ll> A(n);
    set<ll> s;
    rep(i,n) {
        cin>> A[i];
        if (A[i] != -1) {
            if (s.count(A[i])) {
                cout << "No" << endl;
                return 0;
            }
            s.insert(A[i]);
        }
    }
    queue<ll> ans;
    for (int i = 1;i <= n; i++) {
        if (!s.count(i)) {
            ans.push(i);
        }
    }
    cout << "Yes" << endl;

    for (int i = 0;i < n; i++) {
        if (A[i] != -1) {
            cout << A[i] << " ";
        }else {
        cout << ans.front() << " ";
        ans.pop();
        }

    }

    return 0;
}
