class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int M = 1e9 + 7;
        stack<pair<int,int>> st;
        int n = arr.size();
        vector<int> left(n); 
        vector<int> right(n); 

    
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1; 
            }
            else{
                left[i] = st.top().second;
            }
            st.push({arr[i], i});
        }

        stack<pair<int,int>> st1;
        for(int i = n - 1; i >= 0; i--){

            while(!st1.empty() && st1.top().first > arr[i]){ 
                st1.pop();
            }
            if(st1.empty()){
                right[i] = n;
            }
            else{
                right[i] = st1.top().second;
            }
            st1.push({arr[i], i});
        }

        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long left_count = (long long)i - left[i]; 
            long long right_count = (long long)right[i] - i;
            
            long long contribution = (arr[i] * left_count) % M;
            contribution = (contribution * right_count) % M;
            
            ans = (ans + contribution) % M;
        }
        
        return (int)ans;
    }
};