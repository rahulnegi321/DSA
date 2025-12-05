class Solution {
public:
    int countPartitions(vector<int>& nums) {
      int count = 0;
      long long sum = accumulate(nums.begin(),nums.end(),0);
      long long temp = 0;
      for(int i = 0;i<nums.size()-1;i++){
        temp = temp + nums[i];
        if(abs((sum-temp)-temp)%2 == 0){
            count++;
        }
      }
      return count;  
    }
};