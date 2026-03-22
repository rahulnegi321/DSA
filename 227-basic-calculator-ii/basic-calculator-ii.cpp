class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        char sign =  '+';
        int curr = 0;
        int n  =s.size();
        for(int  i = 0;i<s.size();i++){
            if(s[i] == ' '){
                continue;
            }
            if(isdigit(s[i])){
                int curr = 0;
                while(i < n && isdigit(s[i])){
                    curr = curr*10 + (s[i]-'0');
                    i++;
                }
                i--;
                if(sign == '+'){
                    st.push(curr);
                }
                else if(sign == '-'){
                    st.push(-(curr));
                }
                else if(sign == '*'){
                    int temp = st.top();
                    st.pop();
                    int temp2 = temp*(curr);
                    st.push(temp2);
                }
                else{
                    int temp = st.top();
                    st.pop();
                    int temp2 = temp/(curr);
                    st.push(temp2);
                }
            }
            else{
                sign = s[i];
            }
        }
        int sum = 0;
        while(st.size()){
           sum += st.top();
           st.pop();
        }
        return sum;
    }
};