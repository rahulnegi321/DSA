class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans  = 0;
        int n = nums.size();
        int i = 0;
        while(i < n){
            while(i+1 < n && nums[i+1] > nums[i]){
                i++;
            }
            if(i+1 == n){
                return ans + nums[i];
            }
            ans = ans + nums[i];
          
            while(i+1 < n && nums[i+1] <= nums[i]){
              i++;
            }
            if(i+1 == n){
                break;
            }
            ans = ans - nums[i];
        }
        return ans;
    }
};