class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0;
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
           while(nums[i] > k*1LL*nums[left]){
             left++;
           }
           ans = max(ans,i-left+1);
        }
        return n-ans;
    }
};