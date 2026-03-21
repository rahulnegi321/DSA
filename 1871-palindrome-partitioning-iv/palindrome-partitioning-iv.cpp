class Solution {
public:
    int ispalindrome(int left,int right,string &s,vector<vector<int>>&dp){
        if(left == right){
            return dp[left][right] = 1;
        }
        if(right-left == 1 && s[left]==s[right]){
            return dp[left][right] = 1;
        }
        if(s[left]==s[right] && dp[left+1][right-1] == 1){
            return dp[left][right] = 1;
        }
        else if(s[left] == s[right] && dp[left+1][right-1] == -1){
            return dp[left][right] = ispalindrome(left+1,right-1,s,dp);
        }
        return dp[left][right] = 0;
    }
    int helper(int ind,int count,string &s,vector<vector<int>>&dp,vector<vector<int>>&dp2){
        if(count == 3 && ind == s.size()){
            return 1;
        }
        if(ind == s.size()){
            return 0;
        }
        if(count > 3){
            return 0;
        }
        if(dp[ind][count] != -1){
            return dp[ind][count];
        }
        int ans = 0;
        for(int i = ind;i<s.size();i++){
            if(ispalindrome(ind,i,s,dp2)){
                ans = ans | helper(i+1,count+1,s,dp,dp2);
            }
        }
        return dp[ind][count] =  ans;
    }
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        vector<vector<int>>dp2(n,vector<int>(n,-1));
        return helper(0,0,s,dp,dp2);
    }
};