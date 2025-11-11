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
    ll x;
    cin >> x;
    set<ll> a;

    // 桁
    for (int i = 1; i <= 18; i++) {
        // 1桁目
        for (ll j = 1; j <= 9; j++) {
            // 公差
            for (ll k = -9; k <= 9; k++) {
                ll temp = j;
                ll base = j;
                while(1) {
                    if ((int) to_string(temp).length() == i) break; // 桁数がiを超えたら終了
                    ll next = base + k;
                    if (next < 0 || next > 9) break; // 0-9の範囲外なら終了
                    base = next;
                    temp = temp * 10 + base; // 数字を構築
                }
                a.insert(temp);
            }
        }
    }


    auto ans = lower_bound(all(a), x);

    cout << *ans << endl;

    return 0;
}
