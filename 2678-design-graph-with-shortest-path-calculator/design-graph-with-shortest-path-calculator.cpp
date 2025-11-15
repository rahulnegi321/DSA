class Graph {
public:
    vector<vector<pair<int,int>>>adj;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
      adj.resize(n);
    
      for(auto it : edges){
        adj[it[0]].push_back({it[1],it[2]});
      }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>>q;
        q.push({0,node1});
        vector<int>dis(n,INT_MAX);
        dis[node1] = 0;
        while(!q.empty()){
            int distance = -q.top().first;
            int node = q.top().second;
            q.pop();
            if(distance > dis[node]) continue;
            if(node == node2){
                return distance;
            }
            for(auto it : adj[node]){
                int dist = distance + it.second;
                if(dis[it.first] > dist){
                    dis[it.first] = dist;
                    q.push({-dis[it.first],it.first});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */