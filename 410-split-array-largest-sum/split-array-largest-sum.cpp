class Solution {
public:
    
    int check(long long mid,vector<int>&nums,int k){
        int count = 1;
        int curr = 0;
        int maxi = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]  > mid){
                return -1;
            }
            if(curr + nums[i] > mid){
                count++;
                curr = nums[i];
            }
            else{
                curr += nums[i];
                maxi = max(maxi,curr);
            }
        }
        if(count <= k){
            return maxi;
        }
        else{
            return -1;
        }
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        int maxi = 0;
        for(auto it : nums){
            maxi = max(it,maxi);
            sum += it;
        }
        if(k > nums.size()){
            return -1;
        }
        if(k == nums.size()){
            return maxi;
        }
        if(k == 1){
            return (int)sum;
        }
        long long low = 1;
        long long high = sum;
        int ans = 0;
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(check(mid,nums,k) != -1){
                ans = check(mid,nums,k);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};