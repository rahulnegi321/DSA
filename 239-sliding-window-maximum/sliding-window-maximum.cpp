class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        priority_queue<int>q;
        int n = nums.size();
        int left = 0;
        vector<int>ans;
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
            q.push(nums[i]);
            if(i-left+1 > k){
                mpp[nums[left]]--;
                left++;
            }
            if(i-left+1 == k){
                while(mpp[q.top()] == 0){
                    q.pop();
                }
                ans.push_back(q.top());
            }
        }
        return ans;
    }
};