class Solution {
public:
    long long helper(vector<int>&power,vector<long long>&dp,unordered_map<int,int>&mpp,int ind){
      if(ind >= power.size()){
        return 0;
      }
   
      if(dp[ind] != -1){
        return dp[ind];
      }

      long long nottake = helper(power,dp,mpp,ind+1);
      long long current = power[ind];
      long long total = mpp[power[ind]]*current;
      auto it = lower_bound(power.begin()+ind,power.end(),current+3);
      int next = distance(power.begin(),it);
      long long take = total + helper(power,dp,mpp,next);
      return dp[ind] = max(nottake,take);
    }
    long long maximumTotalDamage(vector<int>& power) {
        long long n = power.size();
        unordered_map<int,int>mpp;
        for(int i = 0;i<n;i++){
            mpp[power[i]]++;
        }
        set<int>temp(power.begin(),power.end());
        vector<int>ans(temp.begin(),temp.end());
        vector<long long>dp(n,-1);
        return helper(ans,dp,mpp,0);
    }
};