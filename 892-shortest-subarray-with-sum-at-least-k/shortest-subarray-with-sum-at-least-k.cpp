class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        long long sum = 0;
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
           sum += nums[i];
           if(sum >= k){
             ans = min(ans,i+1);
           }
           while(q.size() && sum - q.top().first >= k){
             ans = min(ans,i-q.top().second);
             q.pop();
           }
           q.push({sum,i});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};