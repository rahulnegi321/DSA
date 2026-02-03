class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        long long sum = 0;
        int left = 0;
        for(int i = 0;i<nums.size();i++){
           sum += nums[i];
           while((long long)(nums[i])*(i-left+1) - sum > k){
             sum -= nums[left];
             left++;
           }
           ans = max(ans,i-left+1);
        }
        return ans;
    }
};