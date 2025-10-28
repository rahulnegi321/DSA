class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>temp(n+1,0);
        for(int i = 0;i<queries.size();i++){
            temp[queries[i][0]]--;
            temp[queries[i][1]+1]++;
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
};