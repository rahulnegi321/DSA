class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count1  = 0;
        int g = 0;
        for(auto x : nums){
            if(x == 1){
                count1++;
            }
            g = gcd(g,x);
        }
        if(count1 > 0){
            return nums.size()-count1;
        }
        if(g > 1){
            return -1;
        }
        int mini = nums.size();
        for(int i = 0;i<nums.size();i++){
            int g = 0;
            for(int j = i;j<nums.size();j++){
                g = gcd(g,nums[j]);
                if(g == 1){
                    mini = min(mini,j-i);
                    break;
                }
            }
        }
        return mini + nums.size() -1;
    }
};