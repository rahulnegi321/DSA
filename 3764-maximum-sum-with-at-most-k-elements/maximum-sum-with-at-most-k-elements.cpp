class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int>q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            int temp = limits[i];
            sort(grid[i].begin(),grid[i].end());
            for(int j = m-1;j>=0;j--){
               if(temp == 0){
                break;
               }
               q.push(grid[i][j]);
               temp--;
            }
        }
        long long ans  = 0;
        while(!q.empty() && k != 0){
            ans = ans + q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};