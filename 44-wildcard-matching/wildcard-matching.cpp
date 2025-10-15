class Solution {
public:
    int helper(string& s,string& p,vector<vector<int>>&dp,int ind,int idx){
        if(ind == s.size() && idx == p.size()){
            return 1;
        }
        if(idx >= p.size()){
            return 0;
        }
        if(ind >= s.size()){
            if(idx >= p.size()){
                return 0;
            }
            int find = 1;
            for(int i = idx;i<p.size();i++){
                if(p[i] != '*'){
                    find = 0;
                }
            }
            return find;
        }
        if(dp[ind][idx] != -1){
            return dp[ind][idx];
        }
        int take = 0;
        if(s[ind] != p[idx] && p[idx] != '?' && p[idx] != '*'){
            return dp[ind][idx] = 0;
        }
        if(s[ind] == p[idx] || p[idx] == '?'){
            take = helper(s,p,dp,ind+1,idx+1);
        }
        if(p[idx] == '*'){
            int empty = helper(s,p,dp,ind,idx+1);
            int lele = helper(s,p,dp,ind+1,idx);
            take = empty | lele;
        }
        return dp[ind][idx] = take;
    }
    bool isMatch(string s, string p) {
     int count = 0;
      for(int i =0;i<p.size();i++){
        if(p[i] == '*'){
            count++;
        }
      }
      if(count == 0 && p.size() < s.size()){
        return false;
      }
      int n = s.size();
      int m = p.size();
      vector<vector<int>>dp(n,vector<int>(m,-1));
      if(helper(s,p,dp,0,0) == 1){
        return true;
      }
      return false;
    }
};