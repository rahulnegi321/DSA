class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>prev_greater;
        stack<int>st;
        int n = nums.size();
        unordered_map<int,int>mpp;
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
          mini = min(mini,nums[i]);
          mpp[i] = mini;
        }
        for(int i = 0;i<n;i++){
            while(st.size() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                prev_greater.push_back(-1);
            }
            else{
                prev_greater.push_back(st.top());
            }
            st.push(i);
        }
        for(int i = n-1;i>=0;i--){
            int lastgreater = prev_greater[i];
            if(lastgreater == -1){
                continue;
            }
            int minimum = mpp[lastgreater];
            if(minimum < nums[i]){
                return true;
            }
        }
        return false;
    }
};