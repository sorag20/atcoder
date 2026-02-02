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

    ll n;
    cin >> n;
    string s;
    cin>>s;
    ll q;
    cin>>q;
    map<char, stack<int>> mp;
    vector<ll> updated_at(n);
    ll lower_updated_at = -1,upper_updated_at = -1;
    rep(i,q) {
        ll t, x;
        char c;
        cin>>t>>x>>c;
        x--;
        if (t == 1) {
            s[x] = c;
            updated_at[x] = i;
        } else if (t == 2) {
            chmax(lower_updated_at, i);
        } else {
            chmax(upper_updated_at, i);
        }
    }
    rep(i,n) {
        char c = s[i];
        if (lower_updated_at == -1 && upper_updated_at == -1) {
            cout << c;
        }else if (lower_updated_at > upper_updated_at) {
            if (updated_at[i] < lower_updated_at) {
                char show = tolower(c);
                cout << show;
            } else {
                cout << c;
            }
        }else if (lower_updated_at < upper_updated_at) {
            if (updated_at[i] < upper_updated_at) {
                char show = toupper(c);
                cout << show;
            }  else {
                cout << c;
            }
        }
    }
    cout << endl;

    return 0;
}
