void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); 
    cout << 1 << endl;
    visited[1] = true;
    while (!S.empty()) {
        int v = S.top();
        if (adj[v].empty()) {
            S.pop();
            continue;
        }
       int p = adj[v].front();
       if (!visited[p]) {
           S.push(p);
           visited[p] = true;
           cout << p << endl;
       } else {
           adj[v].pop_front();
       }
    }
}
//NguyenThuyLinh_20225031
