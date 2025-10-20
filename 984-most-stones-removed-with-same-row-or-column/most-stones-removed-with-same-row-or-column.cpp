class Solution {
public:

    int find(int x,vector<int>&parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x],parent);
    }
    void Union(int x,int y,vector<int>&rank,vector<int>&parent){
        int parent_x = find(x,parent);
        int parent_y = find(y,parent);
        if(parent_x == parent_y){
            return;
        }
        if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }
        else if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
        return;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>parent;
        vector<int>rank(n,0);
        for(int i = 0;i<n;i++){
            parent.push_back(i);
        }
        for(int i = 0;i<stones.size();i++){
            for(int j = i+1;j<stones.size();j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Union(i,j,rank,parent);
                }
            }
        }
        unordered_map<int,int>mpp;
        for(int i = 0;i<n;i++){
            int parent_x  = find(i,parent);
            mpp[parent_x]++;
        }
        int count = 0 ;
        for(auto it : mpp){
            if(it.second > 1){
                count = count + it.second - 1;
            }
        }
        return count;
    }
};