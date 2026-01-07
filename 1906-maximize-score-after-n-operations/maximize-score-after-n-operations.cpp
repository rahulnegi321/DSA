class Solution {
public:
    int N;
    int helper(int count, vector<int>& nums, vector<int>& vis, map<int,map<string,int>>&dp) {
        if (count > N + 1) {
            return 0;
        }
        string temp = "";
        for(int i = 0;i<vis.size();i++){
            if(vis[i] == 0){
                temp += '0';
            }
            else{
                temp += '1';
            }
        }
        if(dp.count(count)){
            if(dp[count].count(temp)){
                return dp[count][temp];
            }
        }
        int ans = 0;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i] == 1) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (vis[j] == 1) {
                    continue;
                }
                vis[i] = 1;
                vis[j] = 1;
                ans = count*gcd(nums[i],nums[j]);
                ans = ans + helper(count+1,nums,vis,dp);
                maxi = max(maxi,ans);
                vis[i] = 0;
                vis[j] = 0;
            }
        }
        return dp[count][temp] = maxi;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        N = n / 2;
        vector<int> vis(n, 0);
        map<int,map<string,int>>dp;
        return helper(1,nums,vis,dp);
    }
};