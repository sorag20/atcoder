queue<ll> que;
vl dist(n,-1);
dist[0]=0;
que.push(0);
while(!que.empty()){
    ll v=que.front();
    que.pop();
    for(auto c:g[v]){
      if(dist[c]==-1) {
          dist[c]=dist[v]+1;
          que.push(c);
      }
    }
 }
