class Solution {
public:
    int M = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto it : queries ){
            int idx = it[0];
            int r = it[1];
            int v = it[3];
            int k = it[2];
            while(idx <= r){
                nums[idx] = (nums[idx]*1LL*v)%M;
                idx += k;
            }
        }
        int xr = 0;
        for(auto it : nums){
            xr = xr^it;
        }
        return xr;
    }
};