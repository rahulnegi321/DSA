class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>q;
        vector<double>prob(n,0);
        prob[start_node] = 1;
        q.push({1,start_node});
        while(!q.empty()){
            double pro = q.top().first;
            int end = q.top().second;
            q.pop();
            if(end == end_node){
                return pro;
            }
            if(prob[end] != pro){
                continue;
            }
            for(auto it : adj[end]){
                int node = it.first;
                double probab = it.second;
                if(prob[node] < probab*pro){
                    prob[node] = probab*pro;
                    q.push({prob[node],node});
                }
            }
        }
        return (double)0;
    }
};