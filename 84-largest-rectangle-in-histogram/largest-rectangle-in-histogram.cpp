class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        stack<pair<int,int>>st;
        stack<pair<int,int>>st2;
        vector<int>before(n,-1);
        for(int i = 0;i<heights.size();i++){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            if(st.size() != 0){
                before[i] = st.top().second;
            }
            st.push({heights[i],i});
        }
    
        vector<int>after(n,n);
         for(int i = n-1;i>=0;i--){
            while(!st2.empty() && st2.top().first >= heights[i]){
                st2.pop();
            }
            if(st2.size() != 0){
                after[i] = st2.top().second;
            }
            st2.push({heights[i],i});
         }
            int answer = 0;
            for(int i = 0;i<n;i++){
                int temp = heights[i]*(after[i] - before[i] - 1);
                answer = max(answer,temp);
        }
        return answer;
    }
};