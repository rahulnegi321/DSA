class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = m-1;
        int j = 0;
        int count = 0;
        while(i >= 0 && j < n){
           if(grid[j][i] < 0){
             count = count + n-j;
             i--;
           }
           else{
            j++;
           }
        }
        return count;
    }
};