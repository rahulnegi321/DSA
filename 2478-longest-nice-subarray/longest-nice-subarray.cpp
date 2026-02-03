class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int xr = 0;
        int ans = 1;
        for(int i = 0;i<nums.size();i++){
            while((xr & nums[i]) != 0 && left < i){
               xr ^= nums[left];
               left++;
            }
            xr = xr^nums[i];
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};