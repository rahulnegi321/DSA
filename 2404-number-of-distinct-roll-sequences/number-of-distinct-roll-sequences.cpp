class Solution {
public:
    int M = 1e9+7;
    int helper(int n,int prev,int pp,vector<vector<vector<int>>>&dp){
        if(n == 0){
            return 1;
        }
        if(dp[n][prev][pp] != -1){
            return dp[n][prev][pp];
        }
        int ans = 0;
        for(int i = 1;i<=6;i++){
            if(prev == 0 || (prev != i && pp != i && gcd(i,prev) == 1)){
                ans = (ans + (helper(n-1,i,prev,dp))%M)%M;
            }
        }
        return dp[n][prev][pp] =   ans;
    }
    int distinctSequences(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(7,vector<int>(7,-1)));
        return helper(n,0,0,dp);
    }
};