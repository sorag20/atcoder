#include <iostream>
#include <atcoder/all>
#include <vector>
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
#define ArraySizeOf(array)     (sizeof(array) / sizeof(array[0]))
using namespace std;
using namespace atcoder;

int main()
{
    ll n,t;
    cin >> n >> t;
    vector<int> a(t);
    map<int, vector<int>> gyou;
    map<int, vector<int>> retu;
    set<int> righttaikaku;
    set<int> lefttaikaku;

    int ans = 0;

    rep(i, t)
    {
        cin >> a[i];
        int gyo;
        int ret;
        if (a[i] % n == 0)
        {
            gyo = a[i] / n;
            ret = n;
        }
        else
        {
            gyo = a[i] / n + 1;
            ret = a[i] % n;
        }

        gyou[gyo].push_back(ret);
        retu[ret].push_back(gyo);
        if (a[i] != 1 && (a[i]-1)%(n+1) == 0) {
            righttaikaku.insert(a[i]);
        }
        if (a[i]==1 ) {
            righttaikaku.insert(a[i]);
        }
        if (a[i] != n && (a[i]-1)%(n-1) == 0 && a[i]%n !=0) {
            lefttaikaku.insert(a[i]);
        }
        if (a[i]==n ) {
            lefttaikaku.insert(a[i]);
        }
        if (gyou[gyo].size() == n) {
            ans = i;
            break;
        }
        if (retu[ret].size() == n) {
            ans = i;
            break;
        }
        if (righttaikaku.size() == n) {
            ans = i;
            break;
        }
        if (lefttaikaku.size() == n) {
            ans = i;
            break;
        }
    }
    if (ans == 0)
 {
     cout << -1 << endl;
 } else {
     cout << ans + 1 << endl;
 }
    return 0;
}
