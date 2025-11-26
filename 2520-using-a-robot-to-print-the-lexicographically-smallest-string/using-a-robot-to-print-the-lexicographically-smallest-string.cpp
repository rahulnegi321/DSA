class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char>min_to_right(n);
        stack<char>st;
        int i = n-1;
        while(i >= 0){
            while(!st.empty() && s[i] <= st.top()){
                st.pop();
            }
            if(st.empty()){
                min_to_right[i] = s[i];
                st.push(s[i]);
            }
            else{
                min_to_right[i] = st.top();
            }
            i--;
        }
        i = 0;
        string ans = "";
        while(!st.empty()){
            st.pop();
        }

        while(i < n){
            if(min_to_right[i] == s[i] && (st.empty() || st.top() > s[i])){
                ans.push_back(s[i]);
                i++;
            }
            else if(!st.empty() && min_to_right[i] >= st.top()){
                ans.push_back(st.top());
                st.pop();
            }
            else{
                st.push(s[i]);
                i++;
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};