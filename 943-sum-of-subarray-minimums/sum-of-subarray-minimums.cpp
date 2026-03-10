class Solution {
public:

    int sumSubarrayMins(vector<int>& arr) {
        int M = 1e9+7;
        stack<int>st;
        vector<int>next_smaller;
        int n = arr.size();
        for(int i = n-1;i>=0;i--){
            while(st.size() && arr[st.top()] > arr[i]){
              st.pop();
            }
            if(st.empty()){
                next_smaller.push_back(n);
            }
            else{
                next_smaller.push_back(st.top());
            }
            st.push(i);
        }

        reverse(next_smaller.begin(),next_smaller.end());
        while(st.size()){
            st.pop();
        }            

        vector<int>prev_smaller;

        for(int i = 0;i<n;i++){
            while(st.size() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                prev_smaller.push_back(-1);
            }
            else{
                 prev_smaller.push_back(st.top());
            }
            st.push(i);
        }              

        long long ans = 0;

        for(int i = 0;i<n;i++){
            int next = next_smaller[i]-1;
            int last = prev_smaller[i]+1;
            ans = (ans + (next-i+1)*1LL*(i-last+1)*1LL*arr[i])%M;
        }

        return ans;
    }
};