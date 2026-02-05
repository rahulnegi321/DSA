class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
      int n = nums.size();
      vector<int>result(n,0);
      for(int i = 0;i<nums.size();i++){
        int temp = i;
         if(nums[i] > 0){
            temp = (i+nums[i])%n;
            result[i] = nums[temp];
         }
         else if(nums[i] < 0){
            int dum = abs(nums[i]);
            dum = dum%n;
            temp = (i-dum+n)%n;
            result[i] = nums[temp];
         }
         else{
            result[i] = nums[i];
         }
      }
      return result;
    }
};