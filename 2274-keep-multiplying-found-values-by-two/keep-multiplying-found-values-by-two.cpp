class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>mpp;
        for(int i = 0;i<nums.size();i++){
            mpp.insert(nums[i]);
        }
        while(1){
            if(mpp.count(original)){
                original = original*2;
            }
            else{
                return original;
            }
        }
        return -1;
    }
};