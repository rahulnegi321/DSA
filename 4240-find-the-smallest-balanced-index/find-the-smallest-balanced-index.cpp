class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0*1LL);
        long long product = 1;
        int n = nums.size();
        
        for(int i = n-1;i>=0;i--){
            sum -= nums[i];
            if(i < n-1){
             long long temp = ceil((double)sum/product);
             if(temp < nums[i+1]){
                break;
             }
             product = product*1LL*nums[i+1];
            }
            if(product > sum){
                break;
            }
            if(product == sum){
                return i;
            }
        }
        return -1;
    }
};