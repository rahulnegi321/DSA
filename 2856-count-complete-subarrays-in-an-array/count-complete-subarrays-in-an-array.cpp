class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
       unordered_map<int,int>mpp;
       for(int i =0;i<nums.size();i++){
        mpp[nums[i]]++;
       } 
       int count = 0;
       for(int i = 0;i<nums.size();i++){
        unordered_map<int,int>mp;
        for(int j = i;j<nums.size();j++){
           mp[nums[j]]++;
            if(mp.size() == mpp.size()){
          count++;
        }
        }
       }
       return count;
    }
};