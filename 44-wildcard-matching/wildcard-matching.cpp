class Solution {
public:
    bool found = false;
    int helper(int ind,int idx,string& s,string& p,vector<vector<int>>&dp){
        if(found == true){
            return dp[ind][idx] = 1;
        }
        if(ind == s.size() && idx == p.size()){
            return 1;
            found = true;
        }
        if(ind >= s.size()){
           for(int i = idx;i<p.size();i++){
            if(p[i] != '*'){
                return 0;
            }
           }
           return 1;
        }
        if(dp[ind][idx] != -1){
            return dp[ind][idx];
        }
        int ans = 0;
        if(s[ind] == p[idx] || p[idx] == '?'){
            ans = ans | helper(ind+1,idx+1,s,p,dp);
        }
        else if(p[idx] == '*'){
           ans = ans | helper(ind,idx+1,s,p,dp);
           ans = ans | helper(ind+1,idx,s,p,dp);
        }
        return dp[ind][idx] = ans;
    }
    bool isMatch(string s, string p) {
        if(s == p){
            return true;
        }
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans = helper(0,0,s,p,dp);
        if(ans == 1){
            return true;
        }
        return false;
    }
};