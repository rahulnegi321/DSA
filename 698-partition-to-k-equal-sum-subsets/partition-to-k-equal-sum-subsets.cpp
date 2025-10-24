class Solution {
public:
   vector<int>vis;
   bool backtrack(int i,int k,int sumset,int n,int value,vector<int>&nums){
            if(k == 0){
                return true;
            }
            if(sumset == value){
                return backtrack(0,k-1,0,n,value,nums);
            }
            bool ans = false;
            for(int j = i;j<n;j++){
                if(!vis[j] && sumset + nums[j] <= value){
                    vis[j] = 1;
                    ans = ans | backtrack(j+1,k,sumset + nums[j],n,value,nums);
                    vis[j] = 0;
                }
            }
            return ans;
        }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%k != 0){
            return false;
        }
        int n = nums.size();
        int value = total/k;
        vis.resize(n,0);
        return backtrack(0,k,0,n,value,nums);
    }
};