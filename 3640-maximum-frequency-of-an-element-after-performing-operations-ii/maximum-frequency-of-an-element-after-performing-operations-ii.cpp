class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi  = *max_element(nums.begin(),nums.end());
        int total = maxi + k;
        unordered_map<int,int>freq;
        for(int i = 0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        map<int,int>temp;
        for(int i = 0;i<nums.size();i++){
            int left = max(0,nums[i]-k);
            int right = min(total,nums[i]+k);
            temp[left]++;
            temp[right+1]--;
            temp[nums[i]] = temp[nums[i]]+0;
        }
        int ans = 0;
        int sum = 0;
        for(auto it : temp){
             sum = sum + it.second;
            int fre = freq[it.first];
            int needcon = sum-fre;
            int tem = 0;
            if(needcon - numOperations > 0){
                tem = numOperations;
            }
            else{
                tem = needcon;
            }
            ans = max(tem+fre,ans);
        }
        return ans;
    }
};