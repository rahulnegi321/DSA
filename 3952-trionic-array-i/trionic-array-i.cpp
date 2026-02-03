class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 3){
            return false;
        }
        if(nums[1] <= nums[0]){
            return false;
        }
        int i = 1;
        while(i < n && nums[i] > nums[i-1]){
            i++;
        }
        if(i >= n-1){
            return false;
        }
        while(i < n && nums[i] < nums[i-1]){
            i++;
        }
        if(i == n){
            return false;
        }
        while(i < n && nums[i] > nums[i-1]){
            i++;
        }
        return (i == n);
    }
};