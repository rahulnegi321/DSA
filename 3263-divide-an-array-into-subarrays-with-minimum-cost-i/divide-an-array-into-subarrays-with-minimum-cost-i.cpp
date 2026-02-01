class Solution {
public:
    int minimumCost(vector<int>& nums) {
       int ans = nums[0];
       int one = 100;
       int second = 100;
       for(int i = 1;i<nums.size();i++){
         if(nums[i] <= one){
            second = one;
            one = nums[i];
         }
         else{
            second = min(nums[i],second);
         }
       }
       ans += one;
       ans += second;
       return ans; 
    }
};