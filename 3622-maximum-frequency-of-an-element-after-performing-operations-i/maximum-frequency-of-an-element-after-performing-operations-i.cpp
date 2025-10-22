class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi  = *max_element(nums.begin(),nums.end());
        int total = maxi + k;
        unordered_map<int,int>freq;
        for(int i = 0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<int>diff(total+2,0);
        for(int i = 0;i<nums.size();i++){
            int left = max(0,nums[i]-k);
            int right = min(total,nums[i]+k);
            diff[left]++;
            diff[right+1]--;
        }
        int ans = 0;
        for(int i = 0;i<total+2;i++){
            if(i > 0){
              diff[i] = diff[i-1]+diff[i];
            }
            int fre = freq[i];
            int needcon = diff[i]-fre;
            int temp = 0;
            if(needcon - numOperations > 0){
                temp = numOperations;
            }
            else{
                temp = needcon;
            }
            ans = max(temp+fre,ans);
        }
        return ans;
    }
};