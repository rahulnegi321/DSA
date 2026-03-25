class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>dp2(n,1);
        int maxi = 1;
        for(int i = 0;i<n;i++){
            int count = 0;
            for(int j = 0;j<i;j++){
                if(nums[j] < nums[i]){
                    int prev = dp[i]; 
                    dp[i] = max(dp[i],dp[j]+1);
                    maxi = max(dp[i],maxi);
                    if(dp[i] == dp[j]+1){
                        if(prev == dp[i]){
                            count += dp2[j];
                        }
                        else{
                            count = dp2[j];
                        }
                    }
                }
                dp2[i] = max(1,count);
            }
        }
        if(maxi == 1){
            return nums.size();
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            if(dp[i] == maxi){
                count += dp2[i];
            }
        }
        return count;
    }
};