class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>prev(m,0);
        int ans = 0;
        for(int i = 0;i<n;i++){
            vector<int>curr(m,0);
            for(int j = 0;j<m;j++){
               if(matrix[i][j] == '1'){
                 curr[j] = 1+prev[j];
               }
            }
            prev = curr;
            stack<pair<int,int>>st;
            vector<int>left;
            int k = 0;
            while(k < m){
                while(!st.empty() && st.top().first >= curr[k]){
                    st.pop();
                }
                if(st.empty()){
                    left.push_back(-1);
                }
                else{
                    left.push_back(st.top().second);
                }
                st.push({curr[k],k});
                k++;
            }
            k = m-1;
            while(st.size()){
                st.pop();
            }
            vector<int>right;
            while(k >= 0){
                while(!st.empty() && st.top().first >= curr[k]){
                    st.pop();
                }
                if(st.empty()){
                    right.push_back(m);
                }
                else{
                    right.push_back(st.top().second);
                }
                st.push({curr[k],k});
                k--;
            }
            reverse(right.begin(),right.end());
            for(int j = 0;j<m;j++){
                ans = max(ans,(right[j]-1-(left[j]+1)+1)*curr[j]); 
            }
        }
        return ans;
    }
};