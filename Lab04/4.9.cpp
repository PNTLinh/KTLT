#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    int n = adj.size();
    vector<int> dis(n, 1e9);
    dis[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,0});
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for (auto act: adj[u]){
            int next = act.first;
            int weight = act.second;
            if (weight + dis[u] < dis[next]){
                dis[next]= weight + dis[u];
                pq.push({dis[next], next});
            }
        }
    }
    return dis;
}
//NguyenThuyLinh_20225031
