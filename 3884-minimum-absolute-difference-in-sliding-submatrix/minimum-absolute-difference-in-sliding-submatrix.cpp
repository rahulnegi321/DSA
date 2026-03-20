class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>>ans(m-k+1,vector<int>(n-k+1));
    for(int i = 0;i<=m-k;i++){
        for(int j = 0;j<= n-k;j++){

            vector<int>values;
            for(int x = i;x<i+k;x++){
                for(int y = j;y<j+k;y++){
                    values.push_back(grid[x][y]);
                }
            }
            sort(values.begin(),values.end());
            int mindiff = INT_MAX;
            for(int ind = 1;ind<values.size();ind++){
                if(values[ind] != values[ind-1]){
                    mindiff = min(mindiff, values[ind] - values[ind-1]);
                }
            }
            ans[i][j] = mindiff == INT_MAX ? 0 : mindiff;
        }
    }
        return ans;
    }
};