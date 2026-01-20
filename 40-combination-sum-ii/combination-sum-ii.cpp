class Solution {
public:
    vector<vector<int>>finalans;
    void helper(int ind,int target,vector<int>&candidates,vector<int>&ans){
            if(target == 0){
                finalans.push_back(ans);
                return;
            }
        for(int i = ind;i<candidates.size();i++){
            if(target < candidates[i]){
                break;
            }
            if(i > ind && candidates[i] == candidates[i-1]){
                continue;
            }
            ans.push_back(candidates[i]);
            helper(i+1,target-candidates[i],candidates,ans);
            ans.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        helper(0,target,candidates,ans);
        return finalans;
    }
};