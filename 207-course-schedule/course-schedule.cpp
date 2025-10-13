class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&temp,int node){
        vis[node] = 1;
        if(temp[node] == 1){
            return true;
        }
        else{
            temp[node] = 1;
        }
        for(auto it : adj[node]){
            if(temp[it] == true){
                return true;
            }
            else if(vis[it] == 1){
                continue;
            }
            else if(dfs(adj,vis,temp,it) == true){
                return true;
            }
        }
        temp[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(n,0);
        vector<int>temp(n,0);
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                if(dfs(adj,vis,temp,i) == true){
                    return false;
                }
            }
        }
        return true;
    }
};