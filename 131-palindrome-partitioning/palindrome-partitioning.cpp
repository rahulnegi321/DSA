class Solution {
public:
    vector<vector<string>>finalans;
    bool check(string& s){
        int i = 0;
        int j = s.size()-1;
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void helper(int ind,string& s,vector<string>&ans){
        if(ind >= s.size()){
           finalans.push_back(ans);
        }
        string curr = "";
        for(int i = ind;i<s.size();i++){
            curr += s[i];
            if(check(curr)){
                ans.push_back(curr);
                helper(i+1,s,ans);
                ans.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string>ans;
        helper(0,s,ans);
        return finalans;
    }
};