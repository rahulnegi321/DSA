class Solution {
public:
    int helper(string s,set<string>&temp,int ind,vector<int>&dp){
       if(ind >= s.size()){
        return 1;
       }
       if(dp[ind] != -1){
        return dp[ind];
       }
       int ans = 0;
       for(int i = ind;i<s.size();i++){
          string temp1 = s.substr(ind,i-ind+1);
          if(temp.count(temp1)){
            ans = ans | helper(s,temp,i+1,dp);
          }
       }
       return dp[ind] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>temp(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
        if(helper(s,temp,0,dp) == 1){
            return true;
        }
        return false;
    }
};