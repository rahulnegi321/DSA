class Solution {
public:
    set<string>ans;
    void dfs(int row,int col,vector<vector<char>>&board,unordered_set<string>&words,unordered_set<string>&pre,string curr){
        if(row > board.size() || row < 0 || col > board[0].size() || col < 0 || board[row][col] == '#'){
            return;
        }
        curr += board[row][col];
        if(!pre.count(curr)){
            return;
        }
        if(words.count(curr)){
            ans.insert(curr);
        }
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        char ori = board[row][col];
        board[row][col] = '#';
        for(int i = 0;i<4;i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if(nrow >= 0 && ncol >= 0 && nrow < board.size() && ncol < board[0].size() && board[nrow][ncol] != '#'){
                dfs(nrow,ncol,board,words,pre,curr);
            }
        }
        board[row][col] = ori;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       unordered_set<string>pre;
       unordered_set<string>st(words.begin(),words.end());
       for(int i = 0;i<words.size();i++){
         string temp = "";
         for(auto it : words[i]){
            temp += it;
            pre.insert(temp);
         }
       }
       string curr = "";
       for(int i = 0;i<board.size();i++){
        for(int j = 0;j<board[0].size();j++){
            dfs(i,j,board,st,pre,curr);
            curr = "";
        }
       }
       vector<string>finalans(ans.begin(),ans.end());
       return finalans;
    }
};