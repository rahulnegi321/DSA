class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long>conver;
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            maxi = max(nums[i],maxi);
            conver.push_back(maxi+nums[i]);
        }
        vector<long long>ans;
        long long sum =0;
        for(int i = 0;i<nums.size();i++){
            sum = sum + conver[i];
            ans.push_back(sum);
        }
        return ans;
    }
};