class Solution {
public:
    vector<vector<int>>result;
    void helper(int ind,int target,vector<int>&candidates,vector<int>&ans){

        if(ind >= candidates.size() && target == 0){
            result.push_back(ans);
            return;
        }

        if(ind >= candidates.size()){
            return;
        }
        helper(ind+1,target,candidates,ans);
        if(target >= candidates[ind]){
            ans.push_back(candidates[ind]);
            helper(ind,target-candidates[ind],candidates,ans);
            ans.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        helper(0,target,candidates,ans);
        return result;
    }
};