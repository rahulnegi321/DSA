class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }

        int n = routes.size();
        unordered_map<int,vector<int>>mpp;
        for(int i = 0;i<routes.size();i++){
            for(auto it : routes[i]){
                mpp[it].push_back(i);
            }
        }
        set<int>vis;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto it : mpp[source]){
            q.push({1,it});
            vis.insert(it);
        }
        while(q.size()){
            int curr = q.top().first;
            int bus = q.top().second;
            q.pop();
            for(int i = 0;i<routes[bus].size();i++){
               if(routes[bus][i] == target){
                return curr;
               }
               for(auto it : mpp[routes[bus][i]]){
                 if(vis.count(it)){
                    continue;
                 }
                 q.push({curr+1,it});
                 vis.insert(it);
               }
            }
        }
        return -1;
    }
};