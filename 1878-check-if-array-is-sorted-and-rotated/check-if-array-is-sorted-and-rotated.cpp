class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int ind = n;
        for(int i = 1;i<n;i++){
           if(nums[i] < nums[i-1]){
             ind = i;
             break;
           }
        }
        if(ind == n){
           return true;
        }
        for(int i = 0;i<n-1;i++){
           int curr = (ind+i)%n;
           int temp = (i+ind+1)%n;
           if(nums[curr] > nums[temp]){
            return false;
           }
        }
        return true;
    }
};