class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int count = 0;
        sort(nums.begin(),nums.end());
        int last = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            int temp = nums[i]-k;
            int maxi = nums[i]+k;
            if(last+1 > maxi){
                continue;
            }
            if(last < temp){
                last = temp;
                count++;
                continue;
            }
            last = last+1;
            count++;
        }
        return count;
    }
};