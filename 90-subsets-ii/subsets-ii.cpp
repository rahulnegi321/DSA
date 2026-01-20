class Solution {
public:
    set<vector<int>>finalans;
    
    void helper(int ind,vector<int>&nums,vector<int>&ans){
        if(ind >= nums.size()){
            finalans.insert(ans);
            return;
        }
        
        helper(ind+1,nums,ans);

        ans.push_back(nums[ind]);
        helper(ind+1,nums,ans);
        ans.pop_back();
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        helper(0,nums,ans);
        vector<vector<int>>result(finalans.begin(),finalans.end());
        return result;
    }
};