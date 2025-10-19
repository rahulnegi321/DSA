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

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        vector<int>rank(n,0);
        vector<int>parent;
        for(int i = 0;i<n;i++){
            parent.push_back(i);
        }
        for(auto it : connections){
            int x = it[0];
            int y = it[1];
            Union(x,y,rank,parent);
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            if(parent[i] == i){
                count++;
            }
        }
        return count-1;
    }
};