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
    vector<int> c(9);
    rep(i,9) cin >> c[i];
    // どの順番で、各マスを確認するか
    vector<int> a(9);
    rep(i,9) a[i] = i;
    
    double ans = 0;
    double total = 0;
    double cnt = 0;
    do {
        total++;
        bool ok = true;
        auto check = [&](int i, int j, int k) {
            vector<P> v;
            v.emplace_back(a[i], c[i]);
            v.emplace_back(a[j], c[j]);
            v.emplace_back(a[k], c[k]);
            sort(all(v));
            if (v[0].second == v[1].second) ok = false;
        };
        check(0, 1, 2);
        check(3, 4, 5);
        check(6, 7, 8);
        check(0, 3, 6);
        check(1, 4, 7);
        check(2, 5, 8);
        check(0, 4, 8);
        check(2, 4, 6);
        if (ok) cnt++;
    } while(next_permutation(all(a)));
    ans = cnt / total;
    printf("%.10f\n", ans);
    return 0;
}
