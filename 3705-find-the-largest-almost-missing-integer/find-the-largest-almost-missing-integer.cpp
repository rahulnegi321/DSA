class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        if(k == 1){
            int ans = INT_MIN;
            for(auto it : mpp){
                if(it.second == 1){
                    ans = max(ans,it.first);
                }
            }
            if(ans == INT_MIN){
                return -1;
            }
            return ans;
        }
        if(k == nums.size()){
            int maxi = *max_element(nums.begin(),nums.end());
            return maxi;
        }
        int n = nums.size();
        if(mpp[nums[0]] == 1 && mpp[nums[n-1]] > 1){
            return nums[0];
        }
        else if(mpp[nums[0]] > 1 && mpp[nums[n-1]] == 1){
            return nums[n-1];
        }
        else if(mpp[nums[0]] > 1 && mpp[nums[n-1]] > 1){
            return -1;
        }
        return max(nums[0],nums[n-1]);
    }
};