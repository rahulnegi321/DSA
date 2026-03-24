class Solution {
public:
    int N = 0;
    int helper(int n,vector<int>&dp){
        if(n == 0 || n == 1 || n == 2){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int last = 0;
        int ans = 0;
        n == N ? last = n-1 : last = n;
        for(int i = 1;i<=last;i++){
            int temp = i*helper(n-i,dp);
            ans = max({temp,ans,((n-i)*i)});
        }
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        N = n;
        return helper(n,dp);
    }
};