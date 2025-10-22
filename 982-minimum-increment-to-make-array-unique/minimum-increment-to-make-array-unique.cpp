class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        unordered_map<int,int>mpp;
        for(int  i = 0;i<nums.size();i++){
            if(mpp.find(nums[i]) == mpp.end()){
                mpp[nums[i]]++;
            }
            else{
                int temp =  nums[i-1]+1;
                count = count + temp-nums[i];
                nums[i] = temp;
                mpp[nums[i]]++;
            }
        }
        return count;
    }
};