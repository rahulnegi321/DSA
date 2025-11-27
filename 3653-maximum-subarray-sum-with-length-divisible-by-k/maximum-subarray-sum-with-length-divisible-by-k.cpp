class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>pre(n+1,0);
        for(int i = 0;i<n;i++){
            pre[i+1] = pre[i]+nums[i]; 
        }
        long long ans = LLONG_MIN;
        for(int start = 0;start<k;start++){
            long long curr = 0;
            long long best = LLONG_MIN;
            for(int i = start;i+k-1<n;i=i+k){
                int r = i+k-1;
                long long blocksum = pre[r+1] - pre[i];
                curr = max(blocksum,curr+blocksum);
                best = max(best,curr);
            }
            ans = max(best,ans);
        }
        return ans;
    }
};

