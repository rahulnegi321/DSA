class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mpp;
       int count = 0;
       int sum = 0;
       mpp[0] = 1;
       for(int i = 0;i<nums.size();i++){
        sum = sum + nums[i];
    
            if(mpp.count(sum-k)){
                count = count + mpp[sum-k];
            }
            mpp[sum]++;
       } 
       return count;
    }
};