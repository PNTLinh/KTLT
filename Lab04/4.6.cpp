void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    while ( !Q.empty()){
        int node = Q.front();
        Q.pop();
        if (!visited[node]){
            visited[node] = true;
            cout<< node << endl;
            for ( int neighbor : adj[node]){
                if (!visited[neighbor]){
                    Q.push(neighbor);
                }
            }
        }
    }
}
//NguyenThuyLinh_20225031
