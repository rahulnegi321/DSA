class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        int count = 0;
        vector<int>presum;
        vector<vector<int>>nums = grid;
        for(int i = 0;i<m;i++){
            sum += nums[0][i];
            if(sum <= k){
                count++;
            }
            presum.push_back(nums[0][i]);
        }
        for(int i = 1;i<n;i++){
            sum = 0;
            for(int j=0;j<m;j++){
               sum += nums[i][j];
               sum += presum[j];
               if(sum <= k){
                count++;
               }
               presum[j] += nums[i][j];
            }
        }
        return count;
    }
};