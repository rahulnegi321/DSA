class Solution {
public:
    
    int helper(int ind,int a,vector<int>&stone,vector<vector<int>>&dp){
        if(ind >= stone.size()){
            return 0;
        }
        if(dp[ind][a] != -1){
            return dp[ind][a];
        }
        int maxi = (a == 1 ? INT_MIN : INT_MAX);
        int sum = 0;
        for(int i = ind;i<ind+3 && i < stone.size();i++){
          sum += stone[i];
          if(a){
            maxi = max(maxi,sum + helper(i+1,0,stone,dp));
          }
          else{
            maxi = min(maxi,helper(i+1,1,stone,dp));
          }
        }
        return dp[ind][a] = maxi;
    }
    string stoneGameIII(vector<int>& stoneValue) {
      int n = stoneValue.size();
      vector<vector<int>>dp(n,vector<int>(2,-1));
      int ans = helper(0,1,stoneValue,dp);
      int sum = accumulate(stoneValue.begin(),stoneValue.end(),0);
      int bob = sum - ans;
      return ans > bob ? "Alice" : (ans == bob ? "Tie" : "Bob");
    }
};