class Solution {
public:
    

    bool helper(string &s,int left,int right,vector<vector<bool>>&dp){
        if(left == right){
            return dp[left][right] = true;
        }
        if(s[left] == s[right] && right-left+1 == 3){
            return dp[left][right] = true;
        }
        if(s[left] == s[right] && right-left+1 == 2){
            return dp[left][right] = true;
        }
        if(s[left] == s[right] && dp[left+1][right-1]){
            return dp[left][right] = true;
        }
        return dp[left][right] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int ans = 1;
        vector<vector<bool>>dp(n,vector<bool>(n,-1));
        for(int k = 0;k<n;k++){
            for(int i = 0,j = k;j<n;j++,i++){
               if(helper(s,i,j,dp)){
                 start = i;
                 end = j;
               }
            }
        }
        return s.substr(start,end-start+1);
    }
};