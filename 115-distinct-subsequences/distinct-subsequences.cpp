class Solution {
public:
    int helper(int ind,int idx,string& s,string& t,vector<vector<int>>&dp){
       if(ind >= s.size()){
         if(idx >= t.size()){
            return 1;
         }
         return 0;
       }
       if(dp[ind][idx] != -1){
        return dp[ind][idx];
       }
       int take = 0;
       int nottake = 0;
       if(idx < t.size() && s[ind] == t[idx]){
           take = helper(ind+1,idx+1,s,t,dp);
       }
       nottake = helper(ind+1,idx,s,t,dp);
       return dp[ind][idx] = take + nottake;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return helper(0,0,s,t,dp);
    }
};