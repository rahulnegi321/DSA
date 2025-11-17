class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
       int start = -1;
       for(int i = 0;i<nums.size();i++){
        if(nums[i] == 1){
            if(start == -1){
                start = i;
            }
            else if(i-start-1 >= k){
                start = i;
            }
            else{
                return false;
            }
        }
       }
       return true;
    }
};