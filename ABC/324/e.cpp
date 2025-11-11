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
    ll n; string t;
    cin >> n >> t;
    string reverse_t = t;
    reverse(reverse_t.begin(), reverse_t.end());
    vector<string> s(n);
    vector<string> reverse_s(n);
    rep(i, n) cin >> s[i];
    rep(i, n) reverse_s[i] = s[i];
    rep(i, n) reverse(reverse_s[i].begin(), reverse_s[i].end());
    vector<ll> cnt_1(n, 0), cnt_2(n, 0);

    rep(i,n) {
        int index = 0;
        int start = -1;
        while (index < t.size()) {
            bool found = false;
            for (int j = start+1; j < s[i].size(); j++) {
                if (s[i][j] == t[index]) {
                    cnt_1[i]++;
                    index++;
                    found = true;
                    start = j;
                    break;
                }
            }
            if (!found) break;
        }
    }
    rep(i,n) {
        int index = 0;
        int start = -1;
        while (index < reverse_t.size()) {
            bool found = false;
            for (int j = start+1; j < reverse_s[i].size(); j++) {
                if (reverse_s[i][j] == reverse_t[index]) {
                    cnt_2[i]++;
                    index++;
                    found = true;
                    start = j;
                    break;
                }
            }
            if (!found) break;
        }
    }
    sort(all(cnt_1));
    sort(all(cnt_2));

    ll ans = 0;
    ll t_size = t.size();


    // cnt_1とcnt_2の組み合わせで、合計がn以上になるものを数える
    for (int i = 0; i < n; i++) {
        int index = lower_bound(all(cnt_2), t_size - cnt_1[i]) - cnt_2.begin();
        ans += n - index;
    }
    cout << ans << endl;
    
    return 0;
}
