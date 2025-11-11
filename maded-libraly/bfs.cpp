vector<vector<int>> g(n);
queue<int> que;
vector<int> dist(n);
rep(i,n) dist[i]=-1;
dist[0]=0;
que.push(0);
while(!que.empty()){
    int v=que.front();
    que.pop();
    for(auto c:g[v]){
      if(dist[c]==-1) {
          dist[c]=dist[v]+1;
          que.push(c);
      }
    }
 }
