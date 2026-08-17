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
    ll n,k;
    cin >> n>>k;
    string s;
    cin >> s;
    sort(all(s));
    ll ans = 0;
    do
    {
        ans++;
        // k文字の部分文字列が回文であるかを判定
        bool flag = false;
        rep(i,n) {
            rep(j,k) {
                if (s[i+j] != s[i+k-j-1]) {
                    break;
                }
                // k文字の部分文字列がである
                if (j == k-1) {
                    flag = true;
                }   
            }
        }
        if (flag) ans--;
    } while (std::next_permutation(s.begin(), s.end()));
    cout << ans << endl;
    return 0;
}
