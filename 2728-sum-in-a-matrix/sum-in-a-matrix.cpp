class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int ans = 0;
        cout<<n<<endl;
        cout<<m<<endl;
        for(auto& num : nums){
            sort(num.begin(),num.end());
        }
           for(int j = m-1;j>=0;j--){
            int maxi = 0;
             for(int i = 0;i<n;i++){
                maxi = max(maxi,nums[i][j]);
             }
             ans += maxi;
           }
        return ans;
    }
};