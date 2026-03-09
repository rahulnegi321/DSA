class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n){
            return "0";
        }
        vector<int>next_smaller;
        stack<int>st;
        for(int i = n-1;i>=0;i--){
            while(st.size() && num[st.top()] >= num[i]){
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
        vector<int>vis(n,0);
        int i = 0;
        while(i < n && k){
            if(next_smaller[i] != n && next_smaller[i]-i <= k){
                vis[i] = 1;
                k--;
            }
            i++;
        }
        string ans =  "";
        for(int i = 0;i<n;i++){
            if(vis[i] == 1){
                continue;
            }
            ans += num[i];
        }
        while(k--){
            ans.pop_back();
        }
        i = 0;
        while(i < n && ans[i] == '0'){
            i++;
        }
        int m = ans.size();
        if(i >= m){
            return "0";
        }
        return ans.substr(i,m-i+1);
    }
};