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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    //freopen("input.txt", "r", stdin);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin>> n;
        vector<ll> a(n);
        deque<ll> dq;
        rep(i, n) {
            cin >> a[i];
            dq.push_back(a[i]);
        }
        string ans = "";
        bool exist = false;
        rep(i,n - 4) {
            if (a[i] < a[i+ 1] && a[i + 1] < a[i + 2] && a[i + 2] < a[i + 3] && a[i + 3] < a[i + 4]) {
                exist = true;
            }
            if (a[i] > a[i + 1] && a[i + 1] > a[i + 2] && a[i + 2] > a[i + 3] && a[i + 3] > a[i + 4]) {
                exist = true;
            }
        }
        if (!exist) {
            rep(i,n) ans += "L";
        } else {
            ans += "L";
            ll current = dq.front();
            dq.pop_front();
            bool current_up = true;
            while (!dq.empty()) {
                ll left = dq.front();
                ll right = dq.back();
                if (current_up) {
                    if (current > left && current > right) {
                        if (left < right) {
                            ans += "L";
                            current = left;
                            dq.pop_front();
                        } else {
                            ans += "R";
                            current = right;
                            dq.pop_back();
                        }
                        current_up = false;
                    } else if (current > left) {
                        ans += "L";
                        current = left;
                        dq.pop_front();
                        current_up = false;
                    } else if (current > right) {
                        ans += "R";
                        current = right;
                        dq.pop_back();
                        current_up = false;
                    } else {
                        if (left < right) {
                            ans += "R";
                            current = right;
                            dq.pop_back();
                        } else {
                            ans += "L";
                            current = left;
                            dq.pop_front();
                        }
                    }
                } else {
                    if (current < left && current < right) {
                        if (left < right) {
                            ans += "R";
                            current = right;
                            dq.pop_back();
                        } else {
                            ans += "L";
                            current = left;
                            dq.pop_front();
                        }
                        current_up = true;
                    } else if (current < left) {
                        ans += "L";
                        current = left;
                        dq.pop_front();
                        current_up = true;
                    } else if (current < right) {
                        ans += "R";
                        current = right;
                        dq.pop_back();
                        current_up = true;
                    } else {
                        if (left < right) {
                            ans += "L";
                            current = left;
                            dq.pop_front();
                        } else {
                            ans += "R";
                            current = right;
                            dq.pop_back();
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
