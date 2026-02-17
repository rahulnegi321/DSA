class Solution {
public:
    vector<vector<string>>finalans;
    void helper(int ind,int idx,string &s,vector<string>&ans,unordered_map<string,int>&mpp){
        if(idx == s.size()){
           if(ind != s.size()){
            return;
           }
           finalans.push_back(ans);
           return;
        }
        string temp = s.substr(ind,idx-ind+1);
        if(mpp.count(temp)){
            ans.push_back(temp);
            helper(idx+1,idx+1,s,ans,mpp);
            ans.pop_back();
        }
        helper(ind,idx+1,s,ans,mpp);
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mpp;
        for(auto it : wordDict){
            mpp[it]++;
        }
        vector<string>ans;
        helper(0,0,s,ans,mpp);
        if(finalans.size() == 0){
            return {};
        }
        vector<string>result;
        for(int i = 0;i<finalans.size();i++){
           int n = finalans[i].size();
           string temp = "";
           for(int j = 0;j<finalans[i].size();j++){
             temp += finalans[i][j];
             if(j != n-1){
                temp += ' '; 
             }
           }
           result.push_back(temp);
        }
        return result;
    }
};