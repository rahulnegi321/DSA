class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int>result;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<m;i++){
            int ans = 0;
            for(int j = 0;j<n;j++){
                int count = 0;
                if(grid[j][i] < 0){
                    count++;
                    grid[j][i] = abs(grid[j][i]);
                }
                string temp = to_string(grid[j][i]);
                count = count + temp.size();
                ans = max(ans,count);
            }
            result.push_back(ans);
        }
        return result;
    }
};