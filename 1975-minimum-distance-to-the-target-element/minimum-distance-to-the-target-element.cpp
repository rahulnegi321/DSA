class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = nums.size();
        for(int i = start;i<nums.size();i++){
            if(nums[i] == target){
                ans = i-start;
                break;
            }
        }
        for(int i = start;i>=0;i--){
            if(nums[i] == target){
                ans = min(start-i,ans);
                break;
            }
        }
        return ans;
    }
};