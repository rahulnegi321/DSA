class Solution {
public:
   
    unordered_map<int,vector<int>>mpp;
    int minJumps(vector<int>& arr){
      for(int i = 0;i<arr.size();i++){
        mpp[arr[i]].push_back(i);
      }   
      int n = arr.size();
      if(n == 1){
        return 0;
      }
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
      q.push({0,0});
      vector<int>vis(n,0);
      while(q.size()){
         int step = q.top().first;
         int ind = q.top().second;
         q.pop();
         
         if(ind == n-1){
            return step;
         }
         if(ind >= n || ind < 0){
            continue;
         }
         if(vis[ind] == 1){
            continue;
         }
         vis[ind] = 1;
         if(ind-1 >= 0 && vis[ind-1] == 0){
           q.push({step+1,ind-1});
         }
         if(ind+1 < n && vis[ind+1] == 0){
            q.push({step+1,ind+1});
         }

         for(auto it : mpp[arr[ind]]){
            if(it == ind || vis[it] == 1){
                continue;
            }
            q.push({step+1,it});
         }
         mpp[arr[ind]].clear();
      }
      return -1;
    }
};