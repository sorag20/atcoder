#include <bits/stdc++.h>
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

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll w, h, a, b, x1, y1, x2, y2;
        cin >> w >> h >> a >> b >> x1 >> y1 >> x2 >> y2;
        P left = {x1, y1};
        P right = {x2, y2};
        if (left.first > right.first) {
        }
        P left_nearest, right_nearest;
        // y座標がleftの方が小さい場合
        if (left.second < right.second) {
            left_nearest = {left.first + a, left.second + b};
            right_nearest = right;
        } else if (left.second == right.second) {
            left_nearest = {left.first + a, left.second};
            right_nearest = right;
        } else {
            left_nearest = {left.first + a, left.second};
            right_nearest = {right.first, right.second + b};
        }
        if (right_nearest.first - left_nearest.first < a && right_nearest.second - left_nearest.second < b) {
            cout << "No" << endl;
        } else if (((right_nearest.first - left_nearest.first) % a != 0 && (right_nearest.second - left_nearest.second) < b) ||
                   ((right_nearest.second - left_nearest.second) % b != 0 && (right_nearest.first - left_nearest.first) < a)) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }

    }

    return 0;
}
