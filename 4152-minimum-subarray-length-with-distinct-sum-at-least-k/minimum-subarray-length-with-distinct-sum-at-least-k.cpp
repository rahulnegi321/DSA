class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int left = 0;
        int ans = INT_MAX;
        unordered_map<int,int>mpp;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
           if(mpp.count(nums[i])){
              mpp[nums[i]]++;
             continue;
           }
           mpp[nums[i]]++;
           sum += nums[i];
           while(sum >= k){
             ans = min(ans,i-left+1);
             mpp[nums[left]]--;
             if(mpp[nums[left]] == 0){
                sum -= nums[left];
                mpp.erase(nums[left]);
             }
             left++;
           }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};