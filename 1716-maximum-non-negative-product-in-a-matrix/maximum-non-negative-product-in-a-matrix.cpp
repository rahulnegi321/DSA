class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int M = 1e9+7;
        map<pair<int,pair<int,int>>,long long>mpp;
        priority_queue<pair<long long,pair<int,pair<int,int>>>>q;
        if(grid[0][0] < 0){
            q.push({abs(grid[0][0]),{-1,{0,0}}});
        }
        else{
            q.push({grid[0][0],{1,{0,0}}});
        }
        long long ans = -1;
        bool zero = false;
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j] == 0){
                    zero = true;
                    break;
                }
            }
            if(zero){
                break;
            }
        }
        while(q.size()){
           long long curr = q.top().first;
           int neg = q.top().second.first;
           int row = q.top().second.second.first;
           int col = q.top().second.second.second;
           q.pop();
           if(mpp[{neg,{row,col}}] >= curr){
            continue;
           }
           mpp[{neg,{row,col}}] = curr;
           if(row == n-1 && col == m-1 && neg == 1){
             ans = max(ans,curr);
           }
           if(row+1 < n){
             if(grid[row+1][col] == 0 || curr == 0){
                q.push({0,{1,{row+1,col}}});
             }
             else{
                grid[row+1][col] < 0 ? neg == -1 ? q.push({abs(grid[row+1][col]*1LL*curr),{1,{row+1,col}}}) : q.push({abs(grid[row+1][col]*1LL*curr),{-1,{row+1,col}}}) : q.push({abs(grid[row+1][col]*1LL*curr),{neg,{row+1,col}}});
             }
           }
           if(col+1 < m){
             if(grid[row][col+1] == 0 || curr == 0){
                q.push({0,{1,{row,col+1}}});
             }
             else{
                grid[row][col+1] < 0 ? neg == -1 ? q.push({abs(grid[row][col+1]*1LL*curr),{1,{row,col+1}}}) : q.push({abs(grid[row][col+1]*1LL*curr),{-1,{row,col+1}}}) : q.push({abs(grid[row][col+1]*1LL*curr),{neg,{row,col+1}}});
             }
           }
        }
        if(zero){
            if(ans < 0){
                return 0;
            }
        }
        return (int)(ans%M);
    }
};