class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }
       
        int sum = 0;
        unordered_map<int,int>mpp;
         mpp[0] = -1;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            if(mpp.count(sum)){
             ans = max(ans,i-mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
        return ans;
    }
};