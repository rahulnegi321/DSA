class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        bool soted = true;
            if(nums.size() == 1){
                return 0;
            }
            for(int i = 1;i<nums.size();i++){
                if(nums[i] < nums[i-1]){
                    soted = false;
                    break;
                }
            }
            if(soted){
                return count;
            }
        while(1){
            int mini = INT_MAX;
            for(int i = 1;i<nums.size();i++){
                mini = min(nums[i]+nums[i-1],mini);
            }
            for(int i = 1;i<nums.size();i++){
               if(nums[i]+nums[i-1] == mini){
                 nums[i-1] = mini;
                 count++;
                 for(int j = i;j<nums.size()-1;j++){
                    nums[j] = nums[j+1];
                 }
                 nums.pop_back();
                 break; 
               }
            }
            bool sorted = true;
            if(nums.size() == 1){
                break;
            }
            for(int i = 1;i<nums.size();i++){
                if(nums[i] < nums[i-1]){
                    sorted = false;
                    break;
                }
            }
            if(sorted){
                break;
            }
        }
        return count;
    }
};