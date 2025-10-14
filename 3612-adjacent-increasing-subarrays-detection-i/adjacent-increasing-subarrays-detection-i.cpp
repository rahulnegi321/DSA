class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i = 0;i<=nums.size()-(2*k);i++){
            bool temp = true;
            for(int j = i+1;j<i+k;j++){
               if(nums[j]-nums[j-1] <= 0){
                temp = false;
               }
            }
            if(temp == false){
                continue;
            }
            for(int j = i+k+1;j<i+(2*k);j++){
               if(nums[j]-nums[j-1] <= 0){
                temp = false;
               }
            }
            if(temp == true){
                return true;
            }
        }
        return false;
    }
};