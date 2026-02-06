class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int prev = 1e8;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int l = i+1;
            int r = n-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(target-sum) < abs(prev-target)){
                    prev = sum;
                }
                if(sum > target){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return prev;
    }
};