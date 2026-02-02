#include <bits/stdc++.h>
#include <atcoder/all>
#include <set>
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

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt = 0;
    bool conseq = false;
    int change_start = -1;
    int k_start = -1, k_end = -1;
    rep(i,n) {
        if (s[i] == '1') {
            if (!conseq) {
                conseq=true;
                cnt++;
                if (cnt == k) {
                    k_start = i;
                }
            }

        } else {
            if (conseq) {
                if (cnt == k-1) {
                    change_start = i;
                } else if (cnt == k) {
                    k_end = i;
                }
            }
            conseq = false;
        }
    }
    if (conseq && cnt == k) {
        k_end = n;
    }
    int k_size = k_end-k_start;

    bool showed = false;
    rep(i,n) {
        if (!showed && i == change_start) {
            cout << s.substr(k_start, k_size);
            showed = true;
            i--;
        } else if (i >= k_start && i < k_end) continue;
        else cout <<s[i];
    }
    cout << endl;

    return 0;
}
