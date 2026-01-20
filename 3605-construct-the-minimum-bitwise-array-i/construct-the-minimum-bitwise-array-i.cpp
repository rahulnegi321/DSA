class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>result;
        for(int i = 0;i<nums.size();i++){
            int ans = -1;
            for(int j = 0;j<nums[i];j++){
                if((j | j+1) == nums[i]){
                    ans = j;
                    break;
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};