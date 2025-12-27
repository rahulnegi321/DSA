class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int endpoints = 0;
        int jumps = 0;
        int farthest = 0;
        for(int i =0;i<n-1;i++){
          farthest = max(farthest,nums[i]+i);
          if(i >= endpoints){
             jumps++;
             endpoints = farthest;
          }
        //   if(endpoints >= n){
        //     break;
        //   }
        }
        return jumps;
    }
};