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
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    n--;

    for (ll keta = 1;; keta++) {
        // 前半の文字数
        ll keta2 = (keta+ 1) / 2;
        // その桁に幾つ文字があるか
        ll num = 9;
        rep(i, keta2-1) {
            num *= 10;
        }
        if (n > num) {
            n -= num;
            continue;
        }
        n+= num/9 - 1;
        string s = to_string(n);
        string rs = s;
        reverse(all(rs));
        if (keta % 2 == 1) {
            s.pop_back();
        }
        cout << s << rs << endl;
        return 0;
    }
    
    return 0;
}
