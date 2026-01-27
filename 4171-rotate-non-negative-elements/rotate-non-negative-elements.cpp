class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int count = 0;
        vector<int>mpp;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] >= 0){
                mpp.push_back(i);
            }
        }
        vector<int>dummy = nums;
        if(mpp.size() == 0 || mpp.size() == 1){
            return nums;
        }
        k = k%(mpp.size());
        for(int i = 0;i<mpp.size();i++){
            int curr = mpp[i];
            int to = mpp[(i+k)%mpp.size()];
            dummy[curr] = nums[to];
        }
        return dummy;
    }
};