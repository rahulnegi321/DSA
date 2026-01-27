class Solution {
public:
    int helper(int i,int j,string& s,vector<vector<bool>>&dp){
        if(i == j){
            return dp[i][j] = true;
        }
        if(j-i == 1){
            return dp[i][j] = (s[i]==s[j]);
        }
        return dp[i][j] = (s[i] == s[j] && dp[i+1][j-1] == true);
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int count = 0;
        for(int k = 0;k<n;k++){
            for(int i = 0,j = k;j<n;i++,j++){
               if(helper(i,j,s,dp)){
                count++;
               }
            }
        }
        return count;
    }
};