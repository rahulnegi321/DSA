class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int,pair<int,int>>>q;
        int ans = INT_MAX;
        vector<vector<int>>dis(n+1,vector<int>(m+1,1e5));
        for(int i = 0;i<m;i++){
           q.push({matrix[0][i],{0,i}});
           dis[0][i] = matrix[0][i];
        }
        while(!q.empty()){
            int value = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            if(row == n-1){
                ans = min(value,ans);
                continue;
            }
            if(row+1 < n && col-1 >= 0 && dis[row+1][col-1] > (value + matrix[row+1][col-1])){
               int temp = value + matrix[row+1][col-1];
               dis[row+1][col-1] = temp;
               q.push({temp,{row+1,col-1}});
            }
            if(row+1 < n &&  dis[row+1][col] > (value + matrix[row+1][col])){
               int temp = value + matrix[row+1][col];
                dis[row+1][col] = temp;
               q.push({temp,{row+1,col}});
            }
            if(row+1 < n && col+1 < m &&  dis[row+1][col+1] > (value + matrix[row+1][col+1])){
               int temp = value + matrix[row+1][col+1];
                dis[row+1][col+1] = temp;
               q.push({temp,{row+1,col+1}});
            }
        }
        return ans; 
    }
};