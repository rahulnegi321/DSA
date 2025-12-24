class Solution {
public:
    int helper(int ind,string &s,unordered_map<string,int>&mpp,vector<int>&dp){
        if(ind == s.size()){
            return 1;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int ans = 0;
        for(int i = ind;i<s.size();i++){
            string temp = s.substr(ind,i-ind+1);
            if(mpp.count(temp)){
                ans = ans | helper(i+1,s,mpp,dp);
            }
        }
        return dp[ind] = ans;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int>mpp;
        for(int i =0;i<words.size();i++){
            mpp[words[i]]++;
        }
        vector<string>ans;
        for(int i = 0;i<words.size();i++){
            int n = words[i].size();
            vector<int>dp(n,-1);
            mpp.erase(words[i]);
            if(helper(0,words[i],mpp,dp) == 1){
                ans.push_back(words[i]);
            }
            mpp[words[i]]++;
        }
        return ans;
    }
};