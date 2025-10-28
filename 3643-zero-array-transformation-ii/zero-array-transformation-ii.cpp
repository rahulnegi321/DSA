class Solution {
public:
    bool check(vector<int>&nums,vector<vector<int>>&queries,int mid){
        int n = nums.size();
        vector<int>temp(n+1,0);
        for(int i = 0;i<=mid;i++){
            temp[queries[i][0]] -= queries[i][2];
            temp[queries[i][1]+1] += queries[i][2];
        }
        vector<int>pre;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum = sum + temp[i];
            pre.push_back(sum);
        }
        for(int i =0;i<nums.size();i++){
            if(nums[i] + pre[i] > 0){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int low = 0;
        int high = queries.size()-1;
        int ans = -1;
        bool zero = true;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != 0){
                zero = false;
                break;
            }
        }
        if(zero){
            return 0;
        }
        while(low <= high){
          int mid = low + (high-low)/2;

          if(check(nums,queries,mid)){
            ans = mid+1;
            high = mid-1;
          }
          else{
            low = mid+1;
          }
        }
        return ans;
    }
};