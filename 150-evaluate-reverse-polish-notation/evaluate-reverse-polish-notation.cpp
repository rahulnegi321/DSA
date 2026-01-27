class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/"){
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                int ans = 0;
                if(tokens[i] == "*"){
                    ans = temp1*temp2;
                }
                else if(tokens[i] == "+"){
                    ans = temp1 + temp2;
                }
                else if(tokens[i] == "-"){
                    ans = temp2-temp1;
                }
                else if(tokens[i] == "/"){
                    ans = temp2/temp1;
                }
                st.push(ans);
            }
            else{
                int temp = stoi(tokens[i]);
                st.push(temp);
            }
        }
        return st.top();
    }
};