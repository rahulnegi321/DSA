class Solution {
public:
    int helper(string& s,string& t,int ind,int idx,vector<vector<int>>&dp){
        if(idx == t.size()){
            return 1;
        }
        if(ind == s.size()){
            return 0;
        }
        if(dp[ind][idx] != -1){
            return dp[ind][idx];
        }
        int nottake = 0;
        int take = 0;
        if(s[ind] == t[idx]){
            take = helper(s,t,ind+1,idx+1,dp);
        }
        nottake = helper(s,t,ind+1,idx,dp);
        return dp[ind][idx] = (take+nottake);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(s == t){
            return 1;
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(s,t,0,0,dp);
    }
};