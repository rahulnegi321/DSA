class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>freq;
        for(auto it : nums){
            mpp[it]++;
        }
        for(auto it : mpp){
            freq[it.second]++;
        }
        for(int i = 0;i<nums.size();i++){
            if(freq[mpp[nums[i]]] == 1){
                return nums[i];
            }
        }
        return -1;
    }
};