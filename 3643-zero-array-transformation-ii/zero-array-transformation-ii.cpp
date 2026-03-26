class Solution {
public:
    bool helper(int total,vector<int>&nums,vector<vector<int>>&queries){
        int n = nums.size();
        vector<int>temp(n+1,0);
        for(int i = 0;i<total;i++){
            temp[queries[i][0]] -= queries[i][2];
            temp[queries[i][1]+1] += queries[i][2];
        }
        vector<int>pre;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += temp[i];
            pre.push_back(sum);
        }
        for(int i = 0;i<n;i++){
            if(pre[i] + nums[i] > 0){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int low = 0;
        int high = n;
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(helper(mid,nums,queries)){
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