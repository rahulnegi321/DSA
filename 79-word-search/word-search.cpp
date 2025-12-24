class Solution {
public:
    bool dfs(vector<vector<char>>&board,string &word,int row,int col,vector<vector<int>>&vis,int i){
        int n = board.size();
        int m = board[0].size();
        if(i == word.size()){
            return true;
        }
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        bool ans = false;
        for(int j = 0;j<4;j++){
            int nrow = drow[j] + row;
            int ncol = dcol[j] + col;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && board[nrow][ncol] == word[i]){
               vis[row][col] = 1;
               ans = ans || (dfs(board,word,nrow,ncol,vis,i+1));
               vis[row][col] = 0;
            }
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                   if(dfs(board,word,i,j,vis,1) == true){
                    return true;
                }
                vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};