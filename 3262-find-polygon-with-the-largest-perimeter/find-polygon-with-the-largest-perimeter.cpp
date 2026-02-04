class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n = nums.size();
       long long total = accumulate(nums.begin(),nums.end(),0*1LL);
       for(int i = n-1;i>=2;i--){
         long long temp = total - nums[i];
         if(temp > nums[i]){
            return total;
         }
         total -= nums[i];
       }
       return -1;
    }
};