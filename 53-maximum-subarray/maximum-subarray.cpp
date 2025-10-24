class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int finalans = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            ans = ans + nums[i];
            if(ans > finalans){
                finalans = ans;
            }
            if(ans < 0){
                ans = 0;
            }
        }
        return finalans;
    }
};