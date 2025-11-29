class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum = sum + nums[i];
        }
        if(sum % k == 0){
            return 0;
        }
        return sum%k;
    }
};