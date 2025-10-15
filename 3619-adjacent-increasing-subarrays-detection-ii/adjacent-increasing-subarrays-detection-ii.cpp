class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int first = 1;
        int second = 1;
        int maxi = 1;
        int count = 1;
        int i = 0;
        int n = nums.size();
         while(i+1 < n && nums[i] < nums[i+1]){
                first++;
                i++;
                maxi = max(maxi,first);
            }
            i++;
        while(i < n){
            while(i+1 <n && nums[i] < nums[i+1]){
                second++;
                maxi = max(second,maxi);
                i++;
            }
            i++;
            count = max(count,min(first,second));
            first = second;
            second = 1;
        }
        return max(maxi/2,count);
    }
};