class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n < 3 || m < 3){
            return 0;
        }
        int count = 0;
        for(int i = 0;i+3<=n;i++){
            for(int j = 0;j+3<=m;j++){
                vector<vector<int>>full;
                set<int>st;
               for(int k = i;k<i+3;k++){
                vector<int>one;
                for(int p = j;p<j+3;p++){
                  one.push_back(grid[k][p]);
                  st.insert(grid[k][p]);
                }
                full.push_back(one);
               }
               if(st.size() != 9){
                continue;
               }
               bool square = true;
               for(int i = 1;i<=9;i++){
                 if(!st.count(i)){
                    square = false;
                    break;
                 }
               }
               if(square == false){
                continue;
               }
               int sum = full[0][0] + full[0][1] + full[0][2];
               for(int i = 0;i<3;i++){
                 int temp = full[0][i] + full[1][i] + full[2][i];
                 int temp2 = full[i][0] + full[i][1] + full[i][2];
                 if(temp != sum || temp2 != sum){
                    square = false;
                    break;
                 }
               }
               if(square == false){
                continue;
               }
               int d1= full[0][0] + full[1][1] + full[2][2];
               int d2 = full[0][2] + full[1][1] + full[2][0];
               if(d1 != sum || d2 != sum){
                continue;
               }
               count++;
            }
        }
        return count;
    }
};