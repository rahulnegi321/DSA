class Solution {
public:

    int find(int x,vector<int>&parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x],parent);
    }

    void Union(int x,int y,vector<int>&parent,vector<int>&rank){
        int parent_x = find(x,parent);
        int parent_y = find(y,parent);
        if(parent_x == parent_y){
            return;
        }
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
        return;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int>parent;
        for(int i = 0;i<n;i++){
            parent.push_back(i);
        }
        vector<int>rank(n,0);
        unordered_map<string,int>mail;
        for(int i = 0;i<accounts.size();i++){
            for(int  j = 1;j<accounts[i].size();j++){
                if(mail.find(accounts[i][j]) == mail.end()){
                    mail[accounts[i][j]] = i;
                }
                else{
                    Union(i,mail[accounts[i][j]],parent,rank);
                } 
            }
        }
        vector<vector<string>>temp(n);
        for(auto it : mail){
            int parent_x = find(it.second,parent);
            temp[parent_x].push_back(it.first);
        }
        vector<vector<string>>ans;
        for(int i = 0;i<n;i++){
           if(temp[i].size() == 0){
            continue;
           } 
           vector<string>tempu;
           tempu.push_back(accounts[i][0]);
           sort(temp[i].begin(),temp[i].end());
           for(auto it: temp[i]){
            tempu.push_back(it);
           }
           ans.push_back(tempu);
        }
        return ans;
    }
};