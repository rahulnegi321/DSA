class Solution {
public:
    bool helper(int mid,vector<int>&nums,vector<int>&changeIndices){
        unordered_map<int,int>vis;
        unordered_map<int,int>mpp;
        long long sum = accumulate(nums.begin(),nums.end(),0*1LL);
        for(int i = 0;i<mid;i++){
            vis[changeIndices[i]]++;
        }
        int temp = 0;
        for(int i = 0;i<mid;i++){
            if(vis[changeIndices[i]] != 1){
                vis[changeIndices[i]]--;
                sum--;
                temp++;
            }
            else{
                if(nums[changeIndices[i]-1] <= temp){
                   temp -= nums[changeIndices[i]-1];
                   mpp[changeIndices[i]] = 1;
                   vis[changeIndices[i]]--;
                }
                else{
                    return false;
                }
            }
        }
        for(int i = 1;i<=nums.size();i++){
            if(mpp[i] != 1){
                return false;
            }
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = changeIndices.size();
        int ans = -1;
        int low = 0;
        int high = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(helper(mid,nums,changeIndices)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};