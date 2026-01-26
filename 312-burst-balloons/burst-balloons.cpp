class Solution {
public:
    int memo[302][302];
    int helper(vector<int>&nums,int i,int j){
        if(i+1 >= j){
            return 0;
        }
        int maxi = 0;
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        for(int k = i+1;k<j;k++){
            int ans = nums[i]*nums[k]*nums[j];
            int curr = ans + helper(nums,i,k) + helper(nums,k,j);
            maxi = max(curr,maxi);
        }
        return memo[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                memo[i][j] = -1;
            }
        }
        return helper(nums,0,n-1);
    }
};