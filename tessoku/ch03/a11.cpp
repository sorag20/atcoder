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

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    int ans = lower_bound(all(a), x) - a.begin();
    cout << ans + 1<< endl;
    /*
        ll l = 0, r = n+1;
        while(l <= r) {
            ll mid = (l+r)/2;
            if (a[mid] > x) r = mid - 1;
            else if (a[mid] < x) l = mid + 1;
            else {
                cout << mid + 1<< endl;
                return 0;
            }
            cout << l << ' ' << r << endl;
        }
    */
    

    return 0;
}
