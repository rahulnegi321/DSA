class Solution {
public:
    int solve(vector<int>&nums,int k){
        if(k < 0){
            return 0;
        }
        int left = 0;
        unordered_map<int,int>mpp;
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
            while(mpp.size() > k){
               mpp[nums[left]]--;
               if(mpp[nums[left]] == 0){
                mpp.erase(nums[left]);
               }
                left++;
            }
            count += i-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
        return solve(nums,k)-solve(nums,k-1);
    }
};