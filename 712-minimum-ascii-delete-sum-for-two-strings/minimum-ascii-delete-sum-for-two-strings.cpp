class Solution {
public:
    int helper(int ind,int idx,string& s1,string& s2,vector<vector<int>>&dp){
        if(ind >= s1.size() || idx >= s2.size()){
            return 0;
        }
        if(dp[ind][idx] != -1){
            return dp[ind][idx];
        }
        int skip1 = 0;
        int skip2 = 0;
        int take = 0;
        skip1 = helper(ind+1,idx,s1,s2,dp);
        skip2 = helper(ind,idx+1,s1,s2,dp);
        if(s1[ind] == s2[idx]){
            take = (int)s1[ind] + helper(ind+1,idx+1,s1,s2,dp);
        }
        return dp[ind][idx] = max({skip1,skip2,take});
    }
    int minimumDeleteSum(string s1, string s2) {
        if(s1 == s2){
            return 0;
        }
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int curr = helper(0,0,s1,s2,dp);
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0;i<s1.size();i++){
            sum1 += (int)s1[i];
        }
        for(int  i = 0;i<s2.size();i++){
            sum2 += (int)s2[i];
        }
        return (sum1+sum2-(2*curr));
    }
};