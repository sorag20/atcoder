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

int solve() {
    ll n;
    string s, t;
    cin >> n >>s >> t;
    if (s == t) {
        return 0;
    }
    int const M = 26;
    set<char> st(all(t));
    if (st.size() == M ) {
        return -1;
    }

    set<P> edges;
    vector<int> inDag(M), outDag(M);
    rep(i,n) {
        edges.emplace(s[i]-'a', t[i]-'a');
    }
    for (auto e:edges) {
        outDag[e.first]++;
        inDag[e.second]++;
    }
    rep(i,M) {
        if (outDag[i] > 1) return -1;
    }

    int ans = edges.size();
    scc_graph g(M);
    for (auto [a,b] : edges) {
        if (a == b) ans--;
        else g.add_edge(a,b);
    }
    for (auto grp : g.scc()) {
        if (grp.size() >= 2) {
            bool f = true;
            for (int v:grp) if (inDag[v] > 1) f = false;
            if (f) ans++;
        }
    }
    return ans;
}


// scc
int main()
{
    //freopen("input.txt", "r", stdin);

    cout <<solve() << endl;


    return 0;
}
