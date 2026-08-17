queue<ll> que;
vl dist(n,-1);
dist[0]=0;
que.push(0);
while(!que.empty()){
    ll v=que.front();
    que.pop();
    for(auto u:g[v]){
      if(dist[u]==-1) {
          dist[u]=dist[v]+1;
          que.push(u);
      }
    }
 }
