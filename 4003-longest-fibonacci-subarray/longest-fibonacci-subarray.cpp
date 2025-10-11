class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        for(int i = 0;i<nums.size()-2;i++){
            if(nums[i]+nums[i+1] == nums[i+2]){
                if(count  == 0){
                    count = 3;
                }
                else{
                    count++;
                }
            }
            else{
                count = 0;
            }
            maxi = max(count,maxi);
        } 
        if(maxi == 0){
            return 2;
        }
        return maxi;
    }
};