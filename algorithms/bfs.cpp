void bfs(vector<vector<int> > graph, int visited [], int start){
    int current, hops;
    queue<pair<int, int> > q;
    q.push(make_pair(start, 0));
    visited[start] = 1;
    while(!q.empty()){
        current = q.front().first;
        hops = q.front().second;
        for(int i=0; i<graph[current].size(); i++){
            if(!visited[graph[current][i]]) {
                visited[graph[current][i]] = 1;
                q.push(make_pair(graph[current][i], hops+1));
            }
        }
        ans[current] = hops;
        q.pop();
    }
}
