class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int count  = 0;
        int ans = 0;
        int  n = nums.size();
        while(i < n && j < n){
            nums[i] = nums[j];
            ans++;
            if(j+1 < n && nums[j] == nums[j+1]){
                count++;
            }
            else{
                count = 0;
            }
            if(count == 2){
                while(j < n && nums[j] == nums[i]){
                    j++;
                }
                count = 0;
            }
            else{
                j++;
            }
            i++;
        }
        return ans;
    }
};