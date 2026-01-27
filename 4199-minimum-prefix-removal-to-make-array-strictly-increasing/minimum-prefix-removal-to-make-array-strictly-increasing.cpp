class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int curr  = -1;
        if(n == 1){
            return 0;
        }
        for(int i = n-2;i>=0;i--){
            if(nums[i] >= nums[i+1]){
                curr = i;
                break;
            }
        }
        return curr+1;
    }
};