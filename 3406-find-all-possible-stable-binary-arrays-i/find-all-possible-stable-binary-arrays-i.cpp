class Solution {
public: 
   
    int l = 0;
    int M = 1e9+7;
    int dp[201][201][2];
    int helper(int zero, int one, int curr){
    
        if(one == 0 && zero == 0){
            return 1;
        }

        if(dp[zero][one][curr] != -1){
            return dp[zero][one][curr];
        }
        long long ans = 0;

        if(curr == 1){
           for(int i = 1;i<=min(zero,l);i++){
             ans = (ans+helper(zero-i,one,0))%M;
           }
        }
        if(curr == 0){
           for(int i = 1;i<=min(one,l);i++){
             ans = (ans+helper(zero,one-i,1))%M;
           }
        }

        return dp[zero][one][curr] = (int)(ans % M);
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        
        l = limit;
        memset(dp,-1,sizeof(dp));
        long long ans = 0;
        ans =  (helper(zero,one,1)%M + helper(zero,one,0)%M)%M;
        return (int)ans;
    }
};