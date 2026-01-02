class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
          if(i+3 < nums.size() && nums[i+3] == nums[i]){
            return nums[i];
           }
           if(i+2 < nums.size() && nums[i+2] == nums[i]){
            return nums[i];
           }
           else if(i+1 < nums.size() && nums[i+1] == nums[i]){
            return nums[i];
           }
        }
        return 0;
    }
};