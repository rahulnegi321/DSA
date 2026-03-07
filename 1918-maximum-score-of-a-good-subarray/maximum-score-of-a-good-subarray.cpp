class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k];
        int i = k;
        int j = k;
        int n = nums.size();
        int mini = nums[k];
        while(i > 0 || j < n-1){
           if(i > 0 && j < n-1){
              if(nums[i-1] > nums[j+1]){
                i--;
              }
              else{
                j++;
              }
           }
           else if(i > 0){
             i--;
           }
           else{
            j++;
           }
            mini = min({mini,nums[i],nums[j]});
           ans = max(ans,(j-i+1)*mini);
        }
        
        return ans;
    }
};