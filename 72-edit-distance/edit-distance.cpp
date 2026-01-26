class Solution {
public:
    int helper(int ind,int idx,string& word1,string& word2,vector<vector<int>>&dp){
        if(ind == word1.size() && idx == word2.size()){
            return 0;
        }
        if(ind == word1.size()){
            return word2.size()-idx;
        }
        if(idx == word2.size()){
           return word1.size()-ind;
        }
        if(dp[ind][idx] != -1){
            return dp[ind][idx];
        }
        int insert = 1e9;
        int del = 1e9;
        int rep = 1e9;
        int temp = 1e9;
        if(word1[ind] == word2[idx]){
            temp = helper(ind+1,idx+1,word1,word2,dp);
        }
        insert = 1 +helper(ind,idx+1,word1,word2,dp);
        del = 1 + helper(ind+1,idx,word1,word2,dp);
        rep = 1 + helper(ind+1,idx+1,word1,word2,dp);
        return dp[ind][idx] = min({temp,insert,del,rep});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,word1,word2,dp);
    }
};