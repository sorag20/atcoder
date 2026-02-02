#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
#include <unordered_set>
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

    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin>>s[i];
    vector<vector<ll>> converted_s (h, vector<ll> (w));
    rep(i,h)rep(j,w) {
        converted_s[i][j] = s[i][j] - 'a';
    }
    ll const M = 26;
    vector<vector<ll>> row_cnt(h, vector<ll> (M));
    vector<vector<ll>> col_cnt(w, vector<ll> (M));
    rep(i,h) rep(j,w){
        row_cnt[i][converted_s[i][j]]++;
    }
    rep(i,w) rep(j,h) {
        col_cnt[i][converted_s[j][i]]++;
    }

    auto deletable = [&](vector<ll> x) {
        ll total = 0, k = 0;
        rep(i,M) {
            if (x[i] > 0) {
                total+= x[i];
                k++;
            }
        }
        return total >= 2 && k == 1;
    };

    vector<bool> deleted_row(h);
    vector<bool> deleted_col(w);

    auto del = [&](ll i, ll j) {
        if (deleted_row[i] || deleted_col[j]) return;
        row_cnt[i][converted_s[i][j]]--;
        col_cnt[j][converted_s[i][j]]--;
    };

    bool f = true;
    while(f) {
        f = false;
        vector<ll> del_row, del_col;
        rep(i,h) {
            if (deleted_row[i]) continue;
            if (deletable(row_cnt[i])) {
                del_row.pb(i);
            }
        }
        rep(i,w) {
            if (deleted_col[i]) continue;
            if (deletable(col_cnt[i])) {
                del_col.pb(i);
            }
        }

        for (auto x: del_row) {
            rep(i,w) {
                del(x, i);
                f = true;
            }
            deleted_row[x] = true;
        }

        for (auto x: del_col) {
            rep(i,h) {
                del(i, x);
                f = true;
            }
            deleted_col[x] = true;

        }
    }

    ll ans = 0;
    rep(i,h)rep(j,w) {
        if (!deleted_row[i] && !deleted_col[j]) ans++;
    }
    
    cout << ans << endl;

    return 0;
}
