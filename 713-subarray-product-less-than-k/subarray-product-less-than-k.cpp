class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0){
            return 0;
        }
        int n = nums.size();
        int left = 0;
        int ans = 0;
        int temp = 1;
        int last = -1;
        for(int i = 0;i<nums.size();i++){
           temp *= nums[i];
           while(temp >= k && left < i){
             temp /= nums[left];
             left++;
           }
           if(temp < k){
             int len = i-left+1;
             ans += (len*(len+1))/2;
             if(last >= left){
                int len1 = (last-left+1);
                ans -= (len1*(len1+1))/2;
             }
             last = i;
           }
        }
        return ans;
    }
};