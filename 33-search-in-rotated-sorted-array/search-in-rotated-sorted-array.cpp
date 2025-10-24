class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }
            if((nums[mid] > target && nums[low] > target && nums[mid]-nums[low] >= 0) || (target > nums[mid] && target < nums[low] && nums[mid]-nums[low] <= 0) || (target > nums[mid] && target > nums[low] && nums[mid]-nums[low] >= 0)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};