class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        int left = 0;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(i-left+1 > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            if(i-left+1 == k){
                priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
                for(auto it : mpp){
                    q.push({it.second,it.first});
                    if(q.size() > x){
                        q.pop();
                    }
                }
                int sum = 0;
                while(!q.empty()){
                 sum = sum + (q.top().first)*(q.top().second);
                 q.pop();
               }
               ans.push_back(sum);
            }
        }
        return ans;
    }
};