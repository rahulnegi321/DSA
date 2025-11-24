class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long sum = 0;
        vector<bool>ans;
        for(int i = 0;i<nums.size();i++){
            sum = (2*sum)%50 + nums[i];
            if(sum%5 == 0){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};