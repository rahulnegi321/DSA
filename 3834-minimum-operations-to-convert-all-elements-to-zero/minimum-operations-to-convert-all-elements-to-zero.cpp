class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int count = 0;
        for(auto i : nums){
            while(!st.empty() && st.top() > i){
                count++;
                st.pop();
            }
            if(st.empty() || st.top() != i){
                st.push(i);
            }
        }
        while(!st.empty() && st.top() != 0){
            count++;
            st.pop();
        }
        return count;
    }
};