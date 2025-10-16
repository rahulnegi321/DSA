class Solution {
public:
    int helper(vector<int>&energy,int k,int ind,vector<vector<int>>&dp,int taken){
       if(ind >= energy.size()){
          return 0;
       }
       if(dp[ind][taken] != -1){
        return dp[ind][taken];
       }
       int take = INT_MIN;
       int nottake = INT_MIN;
       take = energy[ind] + helper(energy,k,ind+k,dp,1);
       if(taken == 0 && ind+1 != energy.size()){
        nottake = helper(energy,k,ind+1,dp,0);
       }
       return dp[ind][taken] = max(take,nottake);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(energy,k,0,dp,0);
    }
};