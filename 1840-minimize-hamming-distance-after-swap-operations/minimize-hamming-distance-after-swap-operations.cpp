class Solution {
public:
    
    int find(vector<int>&parents,int x){
        if(x == parents[x]){
            return x;
        }
        return parents[x] = find(parents,parents[x]);
    }

    void uni(int x,int y,vector<int>&parents,vector<int>&rank){
        int parent_x = find(parents,x);
        int parent_y = find(parents,y);
        if(parent_x == parent_y){
            return;
        } 
        if(rank[parent_x] > rank[parent_y]){
            parents[parent_y] = parents[parent_x];
            rank[parent_x]++;
        }
        else if(rank[parent_x] < rank[parent_y]){
            parents[parent_x] = parents[parent_y];
            rank[parent_y]++;
        }
        else{
            parents[parent_x] = parents[parent_y];
            rank[parent_y]++;
        }
        return;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        if(source == target){
            return 0;
        }
        int n = source.size();
        vector<int>parents;
        vector<int>ranks(n,0);
        for(int i = 0;i<n;i++){
            parents.push_back(i);
        }
        for(auto it : allowedSwaps){
            uni(it[0],it[1],parents,ranks);
        }
        unordered_map<int,unordered_map<int,int>>mpp;
        for(int i = 0;i<n;i++){
            int f = find(parents,i);
            mpp[f][source[i]]++;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            int f = find(parents,i);
            if(mpp[f][target[i]] > 0){
                mpp[f][target[i]]--;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};