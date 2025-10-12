class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int finalans = 0;
        for(auto it:mpp){
            if((it.second)%k == 0){
                finalans = finalans + (it.first)*(it.second);
            }
        }
        return finalans;
    }
};