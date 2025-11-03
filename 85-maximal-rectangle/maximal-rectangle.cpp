class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
         int answer = 0;
        vector<int>prev(m,0);
        for(int i = 0;i<n;i++){
            for(int  j = 0;j<m;j++){
               if(matrix[i][j] == '0'){
                prev[j] = 0;
               }
               else{
                prev[j]++;
               }
            }

        stack<pair<int,int>>st;
        stack<pair<int,int>>st2;
        vector<int>before(m,-1);
        for(int k = 0;k<m;k++){
            while(!st.empty() && st.top().first >= prev[k]){
                st.pop();
            }
            if(st.size() != 0){
                before[k] = st.top().second;
            }
            st.push({prev[k],k});
        }
    
        vector<int>after(m,m);
         for(int k = m-1;k>=0;k--){
            while(!st2.empty() && st2.top().first >= prev[k]){
                st2.pop();
            }
            if(st2.size() != 0){
                after[k] = st2.top().second;
            }
            st2.push({prev[k],k});
         }
            for(int k = 0;k<m;k++){
                int temp = prev[k]*(after[k] - before[k] - 1);
                answer = max(answer,temp);
        }
        }
        return answer;
    }
};