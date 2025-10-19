class Solution {
public:

    void Union(int x,int y,vector<int>&rank,vector<int>&parent){
        int x_parent = find(x,parent);
        int y_parent = find(y,parent);
        if(x_parent == y_parent){
            return;
        }
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent; 
        }
        else if(rank[y_parent] > rank[x_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
        return;
    } 

    int find(int x,vector<int>&parent){
       if(x == parent[x]){
         return x;
       }
       return parent[x] = find(parent[x],parent);
    }
    bool equationsPossible(vector<string>& equations) {
       vector<int>rank(26,0);
       vector<int>parent;
       for(int i = 0;i<26;i++){
         parent.push_back(i);
       }
       for(auto it : equations){
        if(it[1] == '='){
            Union(it[0]-'a',it[3]-'a',rank,parent);
        }
       }
       for(int i = 0;i<equations.size();i++){
         int parent_x = find(equations[i][0]-'a',parent);
         int parent_y = find(equations[i][3]-'a',parent);
         if(equations[i][1] == '!'){
            if(parent_x == parent_y){
                return false;
            }
         }
       }
       return true;
    }
};