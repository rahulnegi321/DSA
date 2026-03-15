class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i = 0;i<heights.size();i++){
            while(st.size() && heights[st.top()] < heights[i]){
                st.pop();
            }
            if(!st.empty()){
               ans[st.top()]++;
            }
            st.push(i);
        }
        stack<int>temp;
        for(int i = n-1;i>=0;i--){
            while(temp.size() && heights[temp.top()] < heights[i]){
                temp.pop();
            }
            if(!temp.empty()){
                ans[i]++;
            }
            temp.push(i);
        }
        return ans;
    }
};