class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        while(q.size()){
            int curr = q.front();
            q.pop();
            if(vis[curr] == 1){
                continue;
            }
            vis[curr] = 1;
            for(auto it : rooms[curr]){
                if(vis[it] == 0){
                  q.push(it);
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                return false;
            }
        }
        return true;
    }
};