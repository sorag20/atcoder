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

struct Edge {
    int c, a, b,i;
    Edge(int c, int a, int b, int i = -1): c(c), a(a), b(b), i(i) {}
    bool operator<(const Edge& other) const {return c < other.c;}
};


int main()
{
    //freopen("input.txt", "r", stdin);

    ll m, n, q;
    cin >> n >> m >> q;
    vector<Edge> es;
    rep(i,m) {
        int a, b, c;
        cin>> a>> b >>c;
        a--;b--;
        es.emplace_back(c, a, b);
    }
    sort(all(es));

    vector<Edge> que;
    rep(i,q) {
        int a, b, c ;
        cin>> a>> b>>c;
        a--;b--;
        que.emplace_back(c, a,b,i);
    }
    vector<bool> ans(q);
    sort(all(que));
    int qi = 0;

    dsu uf(n);
    for(auto [c, a, b, _] : es) {
        while(qi < q && que[qi].c < c) {
            auto[nc, na, nb, i]= que[qi];
            qi++;
            ans[i] = !uf.same(na, nb);
        }
        uf.merge(a,b);
    }

    rep(i,q) {
        if (ans[i]) cout <<"Yes" <<endl;
        else cout << "No" << endl;
    }

    return 0;
}
