#include <bits/stdc++.h>
#include <atcoder/all>
#include <vector>
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
#define P pair<int, int>
#define lP pair<ll, ll>
#define rep(i, x) for (int i = 0; i < x; i++)
using namespace std;
using namespace atcoder;
const int INF=1e9;
struct edge{
    int to;
    int leng;
};
int main()
{
    int n,m; cin>>n>>m;
    vector<vector<edge>> g(n);
    vector<int> w(m);
    rep(i,m){
        int u,v; cin>>u>>v>>w[i];
        g[u].push_back({v,w[i]});
    }
    vector<int> dist(n,INF);
    dist[0]=0;
    vector<bool> done(n,false);
    priority_queue<P,vector<P>,greater<P>> que;
    for(int v=0;v<n;v++){
        que.emplace(dist[v],v);
    }
    while(que.size()>0){
        auto [d,v]=que.top();
        que.pop();
        if(done[v]) continue;
        for(auto c:g[v]){
            if(dist[c.to]>dist[v]+c.leng){
                dist[c.to]=dist[v]+c.leng;
                que.emplace(dist[c.to],c.to);
            }
        }
        done[v]=true;
    }
    for(auto c:dist) cout<<c<<endl;
    return 0;
}
