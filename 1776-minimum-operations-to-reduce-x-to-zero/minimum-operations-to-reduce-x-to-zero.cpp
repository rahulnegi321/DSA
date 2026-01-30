class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = accumulate(nums.begin(),nums.end(),0*1LL);
    if(total < x){
        return -1;
    }
    if(total == x){
        return nums.size();
    }
    int n = nums.size();
    for(int i = 0;i<n;i++){
        nums.push_back(nums[i]);
    }
    int ans = INT_MAX;
    int left = 0;
    long long sum = 0;
    for(int i = 0;i<2*n-1;i++){
        sum += nums[i];
        while(sum > x  && left < i){
            sum -= nums[left];
            left++;
        }
        if(sum == x){
            if(left == 0 || (i >= n-1 && left <= n-1)){
                ans = min(ans,i-left+1);
            }
        }
    }
    return ans == INT_MAX ? -1 :ans;
    }
};