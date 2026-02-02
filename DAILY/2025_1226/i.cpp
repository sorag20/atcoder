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

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i,n) cin>>s[i];
    rep(i,n) cin>>t[i];
    ll const INF = 1e18;
    ll si_min = INF, si_max = 0, sj_min = INF, sj_max = 0;
    ll ti_min = INF, ti_max = 0, tj_min = INF, tj_max = 0;
    rep(i,n) {
        rep(j,n) {
            if (s[i][j] == '#') {
                chmin(si_min, i);
                chmax(si_max, i);
                chmin(sj_min, j);
                chmax(sj_max, j);
            }
        }
    }
    rep(i,n) {
        rep(j,n) {
            if (t[i][j] == '#') {
                chmin(ti_min, i);
                chmax(ti_max, i);
                chmin(tj_min, j);
                chmax(tj_max, j);
            }
        }
    }

    vector<string> ns, nt;
    for (int i = si_min;i <= si_max;i++) {
        string z = "";
        for (int j = sj_min;j <= sj_max;j++) {
            z += s[i][j];
        }
        ns.pb(z);
    }

    for (int i = ti_min;i <= ti_max;i++) {
        string z = "";
        for (int j = tj_min;j <= tj_max;j++) {
            z += t[i][j];
        }
        nt.pb(z);
    }
/*
 
    cout << "ns" << endl;

    for (gauto c:ns) {
        cout << c << endl;
    }
    cout << "nt" << endl;

    for (auto c:nt) {
        cout << c << endl;
    }
        */


    vector<vector<string>> rotate_s(4);
    rotate_s[0] = ns;
    for (int k = 1;k <= 3;k++) {
        vector<string> previous = rotate_s[k-1];
        int pre_i = previous.size();
        int pre_j = previous[0].size();
        vector<string> rotated(pre_j);
        rep(i,pre_j) {
            rep(j,pre_i) {
                rotated[i]+= '#';
            }
        }

        rep(i,pre_i) {
            rep(j,pre_j) {
                rotated[j][pre_i - i - 1] = previous[i][j];
            }
        }
        /*
        for (auto c:rotated) {
            cout << c << endl;
        }
            */
        rotate_s[k]= rotated;
    }

    auto isSame = [&](vector<string> x, vector<string> y) -> bool {
        int xs = x.size(), ys = y.size();
        if (xs != ys) return false;
        rep(i,xs) {
            if (x[i].size() != y[i].size()) return false;
        }
        rep(i,xs) {
            rep(j,x[i].size()) {
                if (x[i][j] != y[i][j]) return false;
            }
        }

        return true;
    };

    rep(i,4) {
        if (isSame(rotate_s[i], nt)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
