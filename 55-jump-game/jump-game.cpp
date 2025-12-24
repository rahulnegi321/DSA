class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        if(nums[0] == 0){
            return false;
        }
        int n = nums.size();
        int i = 0;
        int farthest = nums[i]; 
        while(i <= i + farthest){
            farthest = max(farthest,nums[i]);
            i++;
            farthest--;
            if(i == nums.size()){
                return true;
            }
        }
        return false;
    }
};