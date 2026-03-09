class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        pre[0] = nums[0];
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1] | nums[i];
        }
        suf[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            suf[i] = suf[i+1] | nums[i];
        }
        long long temp = 1<<k;
        long long ans = 0;

        for(int i = 0;i<n;i++){
            long long curr = temp*nums[i];
            if(i > 0){
                curr = curr | pre[i-1];
            }
            if(i < n-1){
                curr = curr | suf[i+1];
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};