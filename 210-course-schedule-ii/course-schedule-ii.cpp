class Solution {
public:
    bool helper(vector<vector<int>>&adj,vector<int>&vis,vector<int>&temp,int node,stack<int>&st){
        vis[node] = 1;
        if(temp[node] == 1){
            return true;
        }
        temp[node] = 1;
        for(auto it :adj[node]){
             if(temp[it] == 1){
                return true;
            }
            if(vis[it] == 1){
                continue;
            }
            if(helper(adj,vis,temp,it,st) == true){
                return true;
            }
        }
        temp[node] = 0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n = numCourses;
         vector<int>vis(n,0);
         vector<int>temp(n,0);
         stack<int>st;
         vector<vector<int>>adj(n);
         for(auto pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
         }
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                if(helper(adj,vis,temp,i,st) == true){
                    return {};
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};