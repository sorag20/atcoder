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

    ll n,m,l;
    cin >> n >>m>>l;
    vector<lP> a(n), b(m);
    rep(i,n) {
        cin>>a[i].first;
        a[i].second= i;
    }
    rep(i,m) {
        cin>>b[i].first;
        b[i].second = i;
    }
    set<lP> st;
    rep(i,l) {
        ll c,d;
        cin>> c >> d;
        c--;d--;
        st.insert({c,d});
    }
    sort(gall(a));
    sort(gall(b));
    ll ans = 0;

    for (auto A: a) {
        for(auto B:b) {
            ll ai = A.second,bi = B.second;
            if (st.find({ai,bi}) == st.end()) {
                chmax(ans,A.first+B.first);
                break;
            }
        }
    }

    cout << ans << endl;


    return 0;
}
