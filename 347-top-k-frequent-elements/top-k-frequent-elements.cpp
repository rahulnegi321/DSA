class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto it : mpp){
            q.push({it.second,it.first});
        }
        vector<int>ans;
        while(k && q.size()){
            auto it = q.top();
            q.pop();
            int num = it.second;
            ans.push_back(num);
            k--;
        }
        return ans;
    }
};