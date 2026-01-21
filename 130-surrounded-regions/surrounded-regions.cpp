class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;    
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            if(board[i][0] == 'O'){
              vis[i][0] = 1;
              q.push({i,0});
            }
       
            if(board[i][m-1] == 'O'){
              vis[i][m-1] = 1;
              q.push({i,m-1});
            }
            
        }
        for(int j = 0;j<m-1;j++){
            if(board[0][j] == 'O'){
              vis[0][j] = 1;
              q.push({0,j});
            }    
            
            if(board[n-1][j] == 'O'){
              vis[n-1][j] = 1;
            q.push({n-1,j});
            }
        }
        while(q.size()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int drow[] = {1,-1,0,0};
            int dcol[] = {0,0,1,-1};
            for(int i = 0;i<4;i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};