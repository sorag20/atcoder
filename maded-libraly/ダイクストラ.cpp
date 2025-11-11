struct edge{
    ll to;
    ll len;
};

const ll INF=2e15;
vector<ll> dist(n,INF);
dist[0]=0;
vector<bool> done(n,false);
priority_queue<lP,vector<lP>,greater<lP>> que;
que.emplace(dist[0],0);
while(que.size()>0){
    auto [d,v]=que.top();
    que.pop();
    if(done[v]) continue;
        done[v]=true;
    for(auto c:g[v]){
        if(dist[c.to]>dist[v]+c.len){
            dist[c.to]=dist[v]+c.len;
            que.emplace(dist[c.to],c.to);
        }
    }
}
for(auto c:dist) cout<<c<<endl;

