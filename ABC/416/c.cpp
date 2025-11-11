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

    ll n, k, x;
    cin >> n >> k >> x;
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
    }
    int i = 0;
    vector<string> ans;
    vector<int> idx(n, 0);
    while(i < pow(n, k)) {
        string t = s[idx[0]];
        for (int j = 1; j < k; j++) {
            t += s[idx[j]];
        }
        ans.push_back(t);
        idx[0]++;
        for (int j = 0; j < k - 1; j++) {
            if (idx[j] == n) {
                idx[j] = 0;
                idx[j + 1]++;
            }
        }
        i++;
    }
    sort(all(ans));
    cout << ans[x - 1] << endl;


    return 0;
}
