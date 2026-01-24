class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int>max;
        priority_queue<int,vector<int>,greater<int>>min;
        for(int i = 0;i<n;i++){
            max.push(nums[i]);
            min.push(nums[i]);
        }
        int ans = 0;
        while(n > 0){
         int temp = max.top() + min.top();
         max.pop();
         min.pop();
         n -= 2;
         if(temp > ans){
            ans = temp;
         }
        }
        return ans;
    }
};