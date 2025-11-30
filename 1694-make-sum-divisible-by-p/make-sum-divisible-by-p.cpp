class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        if(nums.size() == 1){
            if(nums[0] % p == 0){
                return 0;
            } else {
                return -1;
            }
        }

        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int target = sum % p;

        if(target == 0){
            return 0;
        }

        if(sum < p){
            return -1;
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % p == target){
                return 1;
            }
        }

        vector<long long> pre;
        sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
            pre.push_back(sum);
        }

        unordered_map<int,int> mpp;
        mpp[0] = -1;

        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            int curr = pre[i] % p;
            int need = (curr - target + p)%p;
            if(mpp.count(need)){
                ans = min(ans, i - mpp[need]);
            }
            mpp[curr] = i;
        }
        if(ans == nums.size()){
            return -1;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
