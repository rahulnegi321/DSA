class Solution {
public:
    int helper(int ind,int ind2,vector<int>&nums1,vector<int>&nums2,vector<vector<vector<int>>>&dp,bool take){
        int n = nums1.size();
        int m = nums2.size();
        if(ind >= n || ind2 >= m){
            if(!take){
                return INT_MIN;
            }
            return 0;
        }
        if(dp[ind][ind2][take] != -1){
            return dp[ind][ind2][take];
        }
        int skip1 = 0;
        int skip2 = 0;
        int take1_2 = 0;
        skip1 = helper(ind+1,ind2,nums1,nums2,dp,take);
        skip2 = helper(ind,ind2+1,nums1,nums2,dp,take);
        take1_2 = nums1[ind]*nums2[ind2] + helper(ind+1,ind2+1,nums1,nums2,dp,true);
        return dp[ind][ind2][take] =  max({skip1,skip2,take1_2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
        return  helper(0,0,nums1,nums2,dp,false);
    }
};