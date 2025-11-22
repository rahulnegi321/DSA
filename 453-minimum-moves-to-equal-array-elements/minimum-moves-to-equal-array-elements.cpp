class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(nums[0] == nums[n-1]){
            return 0;
        }
        int mini = *min_element(nums.begin(),nums.end());
        int count = 0;
        for(auto it : nums){
            count = count + it-mini;
        }
        return count;
    }
};