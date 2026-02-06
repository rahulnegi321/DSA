class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        int n = nums.size();
        if(n < 4){
            return {};
        }
        for(int i = 0;i<=n-4;i++){
          for(int j = i+1;j<n;j++){
            int l = j+1;
            int r = n-1;
            while(l < r){
                long long sum = (long)nums[i] + (long)nums[j] + (long)nums[l] + (long)nums[r];
                if(sum == target){
                   ans.insert({nums[i],nums[j],nums[l],nums[r]});
                   l++;
                }
                else if(sum > target){
                    r--;
                }
                else{
                    l++;
                }
            }
          }
        }
        vector<vector<int>>finalans(ans.begin(),ans.end());
        return finalans;
    }
};