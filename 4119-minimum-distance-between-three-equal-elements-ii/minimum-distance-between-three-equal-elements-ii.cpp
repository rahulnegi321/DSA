class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        map<int,vector<int>>mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
            if(mpp[nums[i]].size() > 3){
                mpp[nums[i]].erase(mpp[nums[i]].begin());
            }
            if(mpp[nums[i]].size() == 3){
                int j = mpp[nums[i]][0];
                int k = mpp[nums[i]][1];
                int l = mpp[nums[i]][2];
                ans = min(ans,(k-j) + (l-k) + (l-j));
            }
        }
        return ans == INT_MAX ? -1 : ans;
        }
};