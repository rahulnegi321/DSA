class Solution {
public:
    int helper(vector<int>&nums,vector<int>&dp,int ind){
        if(ind >= nums.size()-1){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }

        int take = nums.size();
    
        for(int i = 1;i<=nums[ind];i++){
              int ans = 1 + helper(nums,dp,ind+i);
              take = min(take,ans);
        }
        return dp[ind] = take;
    }
    int jump(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n+1,-1);
       return helper(nums,dp,0);
    }
};