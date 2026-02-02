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
using mint = modint998244353;

void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    //freopen("input.txt", "r", stdin);

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<string, mint> dp;

    auto is_palindrome = [&](string x) {
        string t = x;
        reverse(all(x));
        return x == t;
    };

    dp[""] = 1;
    rep(i,n) {
        // このdp[i]を省略する書き方は、最後のdpには[i]が最後の時のやつしか入っていないということ。
        // なぜなら、oldは最初からであり、遷移がない場合は、dpが空になるから
        map<string, mint> old;
        swap(old, dp);
        for (auto [t, num] : old) {
            for (char c = 'A'; c <= 'B';c++) {
                if (s[i] != '?' && s[i] != c) continue;
                string nt = t+c;
                if (nt.size() == k && is_palindrome(nt)) continue;
                if (nt.size() == k) nt.erase(nt.begin());
                dp[nt] += num;
            }
        }
    }

   mint ans;
   for (auto[t,num] : dp) {
    cout << t << ' ' << num.val() << endl;
    ans += num;
   }
   cout << ans.val() << endl;



    return 0;
}
