class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            unordered_map<int,int>mpp1;
            unordered_map<int,int>mpp2;
            for(int j = i;j<nums.size();j++){
                if(nums[j]%2 == 0){
                    mpp2[nums[j]]++;
                }
                else{
                mpp1[nums[j]]++;
                }
                if(mpp1.size() == mpp2.size()){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};