class Solution {
public:
    unordered_map<int,int>dp;
    int minCost(int n) {
        if(n == 1){
            return 0;
        }
        if(dp.count(n)){
            return dp[n];
        }
        int ans = INT_MAX;
        for(int i = 1;i<=n/2;i++){
          int temp = n-i;
          int curr = temp*i;
          ans = min(ans,(curr + minCost(temp) + minCost(i)));
        }
        return dp[n] = ans;
    }
};