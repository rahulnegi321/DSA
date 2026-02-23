class Solution {
public:
    vector<int>presum;
    int helper(int ind,int idx,int ali,vector<int>&stones,vector<vector<vector<int>>>&dp){
        if(ind >= idx){
            return 0;
        }
        if(dp[ind][idx][ali] != -1){
            return dp[ind][idx][ali];
        }
        int ans = 0;
        if(ali){
    int leftGain = presum[idx+1] - presum[ind+1];
    int rightGain = presum[idx] - presum[ind];

    ans = max(
        leftGain + helper(ind+1, idx, 0, stones, dp),
        rightGain + helper(ind, idx-1, 0, stones, dp)
    );
}
else{
    int leftGain = presum[idx+1] - presum[ind+1];
    int rightGain = presum[idx] - presum[ind];

    ans = min(
        -leftGain + helper(ind+1, idx, 1, stones, dp),
        -rightGain + helper(ind, idx-1, 1, stones, dp)
    );
}
        return dp[ind][idx][ali] = ans;
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i = 0;i<stones.size();i++){
          sum += stones[i];
          presum.push_back(sum);
        }
        presum.insert(presum.begin(),0);

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return helper(0,n-1,1,stones,dp);
    }
};