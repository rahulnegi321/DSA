class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int M = 1e9+7;
        for(auto &q : queries){
            int start = q[0];
            int end = q[1];
            int step = q[2];
            int val = q[3];
            while(start < n && start <= end){
                long long temp = (nums[start]*1LL*val)%M;
                nums[start] = (int)temp;
                start += step;
            }
        }
        int xr = 0;
        for(auto it : nums){
            xr ^= it;
        }
        return xr;
    }
};