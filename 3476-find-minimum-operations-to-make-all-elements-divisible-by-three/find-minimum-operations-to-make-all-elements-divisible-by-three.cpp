class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(auto it : nums){
            count = count + min(it%3,3-it%3);
        }
        return count;
    }
};