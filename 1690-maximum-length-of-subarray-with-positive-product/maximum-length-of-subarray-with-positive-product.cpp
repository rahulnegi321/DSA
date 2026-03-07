class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        bool pos = true;
        int l = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                l = i+1;
                pos = true;
                continue;
            }
            if(nums[i] < 0){
                pos = !pos;
            }
            if(pos){
                ans = max(ans,i-l+1);
            }
        }
        l = n-1;
        pos = true;
        for(int i = n-1;i>=0;i--){
            if(nums[i] == 0){
                pos = true;
                l = i-1;
                continue;
            }
            if(nums[i] < 0){
                pos = !pos;
            }
            if(pos){
                ans = max(l-i+1,ans);
            }
        }
        return ans;
    }
};