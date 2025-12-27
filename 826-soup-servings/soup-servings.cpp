class Solution {
public:
    double helper(int a,int b,map<int,map<int,double>>&dp){
        if(a <= 0 && b <= 0){
            return 0.50;
        }
        if(a <= 0){
            return 1.00;
        }
        if(b <= 0){
            return 0.00;
        }
        if(dp.count(a)){
            if(dp[a].count(b)){
                return dp[a][b];
            }
        }
        double ans = 0.25*(helper(a-4,b,dp) + helper(a-3,b-1,dp) + helper(a-2,b-2,dp) + helper(a-1,b-3,dp));
        return dp[a][b] = ans;
    }
    double soupServings(int n) {
        map<int,map<int,double>>dp;
        if(n > 4800){
            return 1.00;
        }
        int m = (n + 24)/25;
        return helper(m,m,dp);
    }
};