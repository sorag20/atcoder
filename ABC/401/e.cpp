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
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> edges(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	
	dsu uf_small(n), uf_large(n);
	
	for (int i = 0; i < n; i++) {
		for (auto j : edges[i]) (j < i ? uf_small : uf_large).merge(i, j);
		cout << (uf_small.size(i) == i + 1 ? uf_large.size(i) - (i + 1) : -1) << "\n";
	}
    return 0;
}
