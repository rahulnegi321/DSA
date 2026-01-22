class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ans;
        int n = temperatures.size();

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(0);
                st.push(i);
            }
            else{
                ans.push_back(st.top()-i);
                st.push(i);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};