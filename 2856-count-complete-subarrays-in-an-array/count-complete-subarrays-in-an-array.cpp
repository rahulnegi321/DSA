class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int k = st.size();
        int n = nums.size();
        int left = 0;
        int ans = 0;
        unordered_map<int,int>mpp;
        for(int right = 0;right < nums.size();right++){
            mpp[nums[right]]++;
            while(mpp.size() == k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            ans = ans + left;
        }
        return ans;
    }
};