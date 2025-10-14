class Solution {
public:
    int thirdMax(vector<int>& nums) {
       long long first = LLONG_MIN;
       long long second = LLONG_MIN;
       long long third = LLONG_MIN;
       for(int i =0;i<nums.size();i++){
         if(nums[i] > first){
            third = second;
            second = first;
            first = nums[i];
         }
         else if(nums[i] > second && nums[i] != first){
            third = second;
            second = nums[i];
         }
         else if(nums[i] > third && nums[i] != second && nums[i] != first){
            third = nums[i];
         }
       }
       if(third ==  LLONG_MIN){
            return (int)first;
       }
       return (int)third;
    }
};